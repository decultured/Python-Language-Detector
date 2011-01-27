/*
 *  language_sample.h
 *  LanguageIdentifier
 *
 *  Created by Jeffrey Graves on 1/4/10.
 *  Copyright 2010 Jeffrey Graves. All rights reserved.
 *
 */

#include "unicode_tester.h"
#include "language_database.h"

class LanguageSample {

private:

	TriGram *Trigrams;
	LanguageDatabase *Languages;
	UnicodeTester UnicodeTest;
	
	void InsertSortedTrigram(TriGram *newTriGram);
	
public:
	int TotalStuffs;
	
	void IdentifyCharacterBlock(wchar_t wideChar);
	
	LanguageSample(LanguageDatabase *languageDatabase, const char *sampleText, int MaxTrigrams, int maxInputLength);
	~LanguageSample();

	const char *Identify();
};
