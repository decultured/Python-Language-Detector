/*
 *  language_database.h
 *  LanguageIdentifier
 *
 *  Created by Jeffrey Graves on 1/4/10.
 *  Copyright 2010 Jeffrey Graves. All rights reserved.
 *
 */
#ifndef LANGUAGE_DATABASE_H
#define LANGUAGE_DATABASE_H

#include "trigram.h"
#include "options.h"

class LanguageDatabase {
	
private:
	
	int NumLanguages;
	
	char *Languages[MAX_LANGUAGES];
	TriGram *HashTable[LANGUAGE_DATABASE_HASH_TABLE_SIZE];	

public:
	LanguageDatabase();
	~LanguageDatabase();
	
	bool LoadFile(const char *pathName, const char *fileName, const char *languageName);
	bool LoadAll(const char *pathName);
	
	int GetNumLanguages() const {return NumLanguages;}
	const char *GetLanguageName(unsigned int LanguageId) const;
	
	TriGram *FindTriGram(wchar_t *trigram) const;
	TriGram *FindTriGram(const TriGram *trigram) const;
	
	void FindNumHashCollisions(unsigned int hashTableSize) const;
};

#endif
