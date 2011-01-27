/*
 *  unicode_tester.cpp
 *  LanguageIdentifier
 *
 *  Created by Jeffrey Graves on 1/20/10.
 *  Copyright 2010 Jeffrey Graves. All rights reserved.
 *
 */

#include "unicode_tester.h"
#include <iostream>

UnicodeTester::UnicodeTester()
{
	TotalChecked = 0;
	for (int i = 0; i < UT_TOTAL_LANGUAGES; i++)
		LanguageCounts[i] = 0;

	LanguageThresholds[UT_JAPANESE] = UT_JAPANESE_THRESHOLD;
	LanguageThresholds[UT_CHINESE] = UT_CHINESE_THRESHOLD;
	LanguageThresholds[UT_KOREAN] = UT_KOREAN_THRESHOLD;
	LanguageThresholds[UT_VIETNAMESE] = UT_VIETNAMESE_THRESHOLD;
	LanguageThresholds[UT_THAI] = UT_THAI_THRESHOLD;
	LanguageThresholds[UT_ARABIC] = UT_ARABIC_THRESHOLD;
	LanguageThresholds[UT_GREEK] = UT_GREEK_THRESHOLD;
	LanguageThresholds[UT_HEBREW] = UT_HEBREW_THRESHOLD;
	LanguageThresholds[UT_ARMENIAN] = UT_ARMENIAN_THRESHOLD;
	LanguageThresholds[UT_CYRILLIC] = UT_CYRILLIC_THRESHOLD;
	
	HighestPercentage = 0;
	HighestLanguage = -1;
	TotalPercentage = 0;
	
}

UnicodeTester::~UnicodeTester()
{
	
}

void UnicodeTester::TestChar(wchar_t testChar)
{
	TotalChecked++;
	
	if (testChar <= 0x02FF)
		return;
	else if ((testChar >= 0x3040 && testChar <= 0x30ff) || (testChar >= 0x31f0 && testChar <= 0x31ff))
		LanguageCounts[UT_JAPANESE]++;
	else if ((testChar >= 0x4E00 && testChar <= 0x9FFF) || (testChar >= 0x3100 && testChar <= 0x312F) || (testChar >= 0x31A0 && testChar <= 0x31BF) || (testChar >= 0x2F00 && testChar <= 0x2FDF))
		LanguageCounts[UT_CHINESE]++;
	else if ((testChar >= 0x1100 && testChar <= 0x11FF) || (testChar >= 0x3130 && testChar <= 0x318F) || (testChar >= 0xA960 && testChar <= 0xA97F) || (testChar >= 0xAC00 && testChar <= 0xD7FF)) 
		LanguageCounts[UT_KOREAN]++;
	else if (testChar >= 0x1E00 && testChar <= 0x1EFF)
		LanguageCounts[UT_VIETNAMESE]++;
	else if (testChar >= 0x0E00 && testChar <= 0x0E7F)
		LanguageCounts[UT_THAI]++;
	else if ((testChar >= 0x0E00 && testChar <= 0x0E7F) || (testChar >= 0x0600 && testChar <= 0x06FF) || (testChar >= 0xFB50 && testChar <= 0xFDFF) || (testChar >= 0xFE70 && testChar <= 0xFEFF))
		LanguageCounts[UT_ARABIC]++;
	else if ((testChar >= 0x1F00 && testChar <= 0x1FFF) || (testChar >= 0x0370 && testChar <= 0x03FF))
		LanguageCounts[UT_GREEK]++;
	else if ((testChar >= 0x0590 && testChar <= 0x05FF))
		LanguageCounts[UT_HEBREW]++;
	else if ((testChar >= 0x0530 && testChar <= 0x058F))
		LanguageCounts[UT_ARMENIAN]++;
	else if ((testChar >= 0x0400 && testChar <= 0x052F))
		LanguageCounts[UT_CYRILLIC]++;
}

float UnicodeTester::GetHighestPercentage()
{
	if (!TotalChecked)
		return 0;
	
	HighestPercentage = 0;
	TotalPercentage = 0;
	HighestLanguage = -1;
	float Percent = 0;
	for (int i = 0; i < UT_TOTAL_LANGUAGES; i++){
		Percent = (float)LanguageCounts[i] / (float)TotalChecked * 100;
		if (Percent > HighestPercentage) {
			HighestPercentage = Percent;
			HighestLanguage = i;
		}
		TotalPercentage += Percent;
	}
	
	return HighestPercentage;
}

const char *UnicodeTester::GetLanguage()
{
	GetHighestPercentage();
	
	if (HighestLanguage > -1 && HighestPercentage > LanguageThresholds[HighestLanguage]) {
		return GetLanguageByCode(HighestLanguage);
	} else if (TotalPercentage > UT_UNKNOWN_THRESHOLD) {
		return "Unknown";
	} else {
		return 0;
	}
}

const char *UnicodeTester::GetLanguageByCode(unsigned int languageCode) const
{
	if (languageCode < 0 || languageCode >= UT_TOTAL_LANGUAGES)
		return 0;
	
	if (languageCode == UT_JAPANESE) {
		return "ja";
	} else if (languageCode == UT_CHINESE) {
		return "zh";
	} else if (languageCode == UT_KOREAN) {
		return "ko";
	} else if (languageCode == UT_VIETNAMESE) {
		return "vi";
	} else if (languageCode == UT_THAI) {
		return "th";
	} else if (languageCode == UT_ARABIC) {
		return "ar";
	} else if (languageCode == UT_GREEK) {
		return "el";
	} else if (languageCode == UT_HEBREW) {
		return "he";
	} else if (languageCode == UT_ARMENIAN) {
		return "hy";
	} else if (languageCode == UT_CYRILLIC) {
		return "ru";
	}
	
	return 0;
}
