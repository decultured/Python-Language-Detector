/*
 *  unicode_tester.h
 *  LanguageIdentifier
 *
 *  Created by Jeffrey Graves on 1/20/10.
 *  Copyright 2010 Jeffrey Graves. All rights reserved.
 *
 */
#ifndef UNICODE_TESTER_H
#define UNICODE_TESTER_H

#include "options.h"


#define UT_TOTAL_LANGUAGES 9
#define UT_JAPANESE 0
#define UT_CHINESE 1
#define UT_KOREAN 2
#define UT_VIETNAMESE 3
#define UT_THAI 4
#define UT_ARABIC 5
#define UT_GREEK 6
#define UT_HEBREW 7
#define UT_ARMENIAN 8
#define UT_CYRILLIC 9

class UnicodeTester {
	
private:
	
	unsigned int LanguageCounts[UT_TOTAL_LANGUAGES];
	float LanguageThresholds[UT_TOTAL_LANGUAGES];
	
	float HighestPercentage;
	float TotalPercentage;
	int HighestLanguage;
	unsigned int TotalChecked;

	const char *GetLanguageByCode(unsigned int languageCode) const;

public:
	
	UnicodeTester();
	~UnicodeTester();
	
	void TestChar(wchar_t testChar);

	float GetHighestPercentage();
	
	const char *GetLanguage();
};

#endif
