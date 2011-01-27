/*
 *  trigram.cpp
 *  LanguageIdentifier
 *
 *  Created by Jeffrey Graves on 1/8/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "trigram.h"
#include "options.h"
#include "murmur/murmur.h"

TriGram::TriGram(wchar_t *nGram)
{
	next = NULL;
	Languages = NULL;
	Count = 1;
	
	WString[3] = 0;

	wcsncpy(WString, nGram,	3);

	Hash = MurmurHash2(WString, TRIGRAM_SIZE, TRIGRAM_HASH_SEED) % LANGUAGE_DATABASE_HASH_TABLE_SIZE;
}

TriGram::~TriGram()
{
	while (Languages != NULL) {
		TriGramLanguage *next = Languages->next;
		delete Languages;
		Languages = next;
	}
}

void TriGram::AddLanguage(unsigned int languageID, int position)
{
	TriGramLanguage *newLanguage = new TriGramLanguage(languageID, position);
	
	if (!Languages) {
		Languages = newLanguage;
		return;
	} else {
		newLanguage->next = Languages;
		Languages = newLanguage;
	}
}
