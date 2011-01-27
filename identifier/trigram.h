/*
 *  trigram.h
 *  Trigram 
 *
 *  Created by Jeffrey Graves on 1/4/10.
 *  Copyright 2010 Jeffrey Graves. All rights reserved.
 *
 */
#ifndef TRIGRAM_H
#define TRIGRAM_H

#include "options.h"

struct TriGramLanguage {
	unsigned int LanguageId;
	int Position;
	
	TriGramLanguage *next;
	
	TriGramLanguage(unsigned int languageId, int position) {LanguageId = languageId; Position = position; next = 0;}
};

struct TriGram {
	wchar_t WString[4];
	
	TriGramLanguage *Languages;
	
	unsigned int Count;
	unsigned int Hash;
	
	TriGram *next;
	
	TriGram(wchar_t *nGram);
	~TriGram();
	
	void AddLanguage(unsigned int languageID, int position);
	
	inline bool operator==(const TriGram &compare) const {
		if (compare.WString[0] == WString[0] && compare.WString[1] == WString[1] && compare.WString[2] == WString[2]) {
			return true;
		}
		return false;
	}
	
	inline bool Equals(const wchar_t *compare) const {
		if (compare[0] == WString[0] && compare[1] == WString[1] && compare[2] == WString[2]) {
			return true;
		}
		return false;
	}
};

#endif
