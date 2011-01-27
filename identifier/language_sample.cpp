/*
 *  language_sample.cpp
 *  LanguageIdentifier
 *
 *  Created by Jeffrey Graves on 1/4/10.
 *  Copyright 2010 Jeffrey Graves. All rights reserved.
 *
 */

#include "language_sample.h"
#include "unicode/utf8.h"
#include <limits.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

// input should be formatted either as UTF-8 or ASCII
LanguageSample::LanguageSample(LanguageDatabase *languageDatabase, const char *sampleText, int MaxTrigrams, int MaxInputLength)
{
	Languages = languageDatabase;
	Trigrams = NULL;
	
	if (!sampleText)
		return;
	
	// Convert sample to UCS-4 (UTF-32)
	int length = strlen(sampleText);
	if (length <= 3)
		return;
	if (length > MaxInputLength)
		length = MaxInputLength;
	wchar_t *widesample = new wchar_t[length];
	memset(widesample, 0, sizeof(wchar_t)*length);
	size_t wide_string_size; 
	wide_string_size = utf8_to_wchar(sampleText, length, widesample, sizeof(wchar_t) * length, 0);
	widesample[length - 1] = 0;

	// Split sample into trigrams
	wchar_t *trigram = new wchar_t[4];
	trigram[0] = 0;
	trigram[1] = towlower(widesample[0]);
	trigram[2] = towlower(widesample[1]);
	trigram[3] = 0;

	int count = 0;
	for (int i = 2; i < length; i++)
	{
		if (count > MaxTrigrams || widesample[i] == 0)
			break;
		
		if (iswpunct(widesample[i]) || iswdigit(widesample[i]) || iswcntrl(widesample[i]))
			widesample[i] = L' ';
		
		if (iswspace(widesample[i]) && iswspace(trigram[2]))
			continue;
		
		trigram[0] = trigram[1];
		trigram[1] = trigram[2];
		trigram[2] = towlower(widesample[i]);

		UnicodeTest.TestChar(widesample[i]);

		if (!Trigrams) {
			Trigrams = new TriGram(trigram);
			continue;
		}
		
		bool found = false;
		TriGram *triPtr = Trigrams;
		TriGram *prev = NULL;
		while (triPtr) {
			if (triPtr->Equals(trigram)) {
				triPtr->Count++;
				found = true;
				
				if (!prev)
					Trigrams = triPtr->next;
				else
					prev->next = triPtr->next;
				
				break;
			}
			prev = triPtr;
			triPtr = triPtr->next;
 		}
		
		if (found)
			InsertSortedTrigram(triPtr);
		else {
			count++;
			InsertSortedTrigram(new TriGram(trigram));
		}
	}

	delete[] trigram;
 	delete[] widesample;
}

void LanguageSample::InsertSortedTrigram(TriGram *newTriGram)
{
	if (!Trigrams) {
		Trigrams = newTriGram;
		return;
	}
	
	if (Trigrams->Count <= newTriGram->Count || !Trigrams->next) {
		newTriGram->next = Trigrams;
		Trigrams = newTriGram;
		return;
	}
	
	TriGram *triPtr = Trigrams;
	while (triPtr) {
		TotalStuffs++;
		if (!triPtr->next || triPtr->next->Count <= newTriGram->Count) {
			newTriGram->next = triPtr->next;
			triPtr->next = newTriGram;
			return;
		}
		
		triPtr = triPtr->next;
	}
}

LanguageSample::~LanguageSample()
{
	if (!Trigrams)
		return;
	
	TriGram *current = Trigrams;
	TriGram *next = current->next;
	while (current) {
		next = current->next;
		delete current;
		current = next;
	}
}

const char *LanguageSample::Identify()
{
	const char *unicodeResult = UnicodeTest.GetLanguage();
	if (unicodeResult)
		return unicodeResult;
	
	int numLangs = Languages->GetNumLanguages();
	int *distances = new int[numLangs];
	memset(distances, 0, numLangs * sizeof(int));
	
	TriGram *triGramFound;
	TriGram *trigram = Trigrams;
	TriGramLanguage *language;
	int rank = 0;
	while (trigram) {
		triGramFound = Languages->FindTriGram(trigram);
	
		if (triGramFound) {
			language = triGramFound->Languages;
			while (language) {
				distances[language->LanguageId] += abs(300 - rank - language->Position);
				language = language->next;
			}
		}
		
		rank++;
		if (rank >= 300)
			break;
		trigram = trigram->next;
	}
	
	int largestVal = 0;
	int bestLanguage = 0;

	for (int i = 0; i < numLangs; i++)
	{
		if (distances[i] > largestVal) {
			largestVal = distances[i];
			bestLanguage = i;
		}
	}

	delete[] distances;

	if (largestVal < 200)
		return "Unknown";
	
	return Languages->GetLanguageName(bestLanguage);
}
