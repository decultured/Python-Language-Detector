/*
 *  language_database.cpp
 *  LanguageIdentifier
 *
 *  Created by Jeffrey Graves on 1/4/10.
 *  Copyright 2010 Jeffrey Graves. All rights reserved.
 *
 */

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "murmur/murmur.h"
#include "language_database.h"

LanguageDatabase::LanguageDatabase(void)
{
	NumLanguages = 0;
	
	int i = 0;
	for (i = 0; i < LANGUAGE_DATABASE_HASH_TABLE_SIZE; i++)	{
		HashTable[i] = NULL;
	}

	for (i = 0; i < MAX_LANGUAGES; i++)	{
		Languages[i] = NULL;
	}
}

LanguageDatabase::~LanguageDatabase(void)
{
	int i = 0;
	for (i = 0; i < LANGUAGE_DATABASE_HASH_TABLE_SIZE; i++)	{
		if (HashTable[i]) {
			TriGram *current = HashTable[i];
			TriGram *next = current->next;
			while (current) {
				next = current->next;
				delete current;
				current = next;
			}
		}
	}
	
	for (i = 0; i < MAX_LANGUAGES; i++)	{
		if (Languages[i])
			delete [] Languages[i];
	}
}

const char *LanguageDatabase::GetLanguageName(unsigned int LanguageId) const
{
	if (LanguageId >= MAX_LANGUAGES || !Languages[LanguageId])
		return NULL;
	return Languages[LanguageId];
}


bool LanguageDatabase::LoadFile(const char *pathName, const char *fileName, const char *languageName)
{
	if (!pathName || !fileName)
		return false;
	
	char *fullPath = new char[strlen(pathName) + strlen(fileName) + 1];
	strcpy (fullPath, pathName);
	strcat (fullPath, fileName);

	std::ifstream::pos_type fileSize;
	std::ifstream file (fullPath, std::ios::in|std::ios::binary|std::ios::ate);
	delete [] fullPath;

	if (file.is_open())
	{
		fileSize = file.tellg();
		file.seekg (0, std::ios::beg);
		
		wchar_t *trigram = new wchar_t[4];
		trigram[3] = 0;		
		int value = 0;
		TriGram *trigramPtr = NULL;
		
		// TODO better looping
		while (!file.eof())
		{
			if (!file.read((char *)trigram, 3 * sizeof(wchar_t)))
				break;
			if (!file.read((char *)&value, sizeof(int)))
				break;
			
			trigramPtr = FindTriGram(trigram);
			if (trigramPtr) {
				trigramPtr->AddLanguage(NumLanguages, value);
			} else {
				trigramPtr = new TriGram(trigram);
				trigramPtr->AddLanguage(NumLanguages, value);
				if (HashTable[trigramPtr->Hash])
					trigramPtr->next = HashTable[trigramPtr->Hash];
				HashTable[trigramPtr->Hash] = trigramPtr;
			}
		}

		Languages[NumLanguages] = new char[strlen(languageName) + 1];
		strncpy(Languages[NumLanguages], languageName, strlen(languageName) + 1);
		NumLanguages++;
		
		delete [] trigram;
		file.close();
	}
	else {
		return false;
	}
	return true;
}

TriGram *LanguageDatabase::FindTriGram(wchar_t *trigramchars) const
{
	unsigned int hash = MurmurHash2(trigramchars, TRIGRAM_SIZE, TRIGRAM_HASH_SEED) % LANGUAGE_DATABASE_HASH_TABLE_SIZE;
	
	TriGram *trigram = HashTable[hash];
	
	while (trigram) {
		if (trigram->Equals(trigramchars))
			return trigram;
		
		trigram = trigram->next;
	}
	return NULL;
}

TriGram *LanguageDatabase::FindTriGram(const TriGram *trigram) const
{
	const wchar_t * twc = trigram->WString;
	TriGram *foundTrigram = HashTable[trigram->Hash];
	
	while (foundTrigram) {
		if(twc[0] == foundTrigram->WString[0] && twc[1] == foundTrigram->WString[1] && twc[2] == foundTrigram->WString[2])
			return foundTrigram;
		foundTrigram = foundTrigram->next;
	}
	return NULL;
}

bool LanguageDatabase::LoadAll(const char *pathName)
{
	// Arabic Languages - Found with the unicode checker
	//	if(!LoadFile("trigrams/ar.tri","Arabic");
	//	if(!LoadFile("trigrams/fa.tri","Farsi");
	//	if(!LoadFile("trigrams/ps.tri","Pashto");
	//	if(!LoadFile("trigrams/ur.tri","Urdu");

	// Cyrillic Languages - Can be found with the unicode checker
	//if(!LoadFile("trigrams/bg.tri","Bulgarian")) return false;
	//if(!LoadFile("trigrams/kk.tri","Kazakh")) return false;
	//if(!LoadFile("trigrams/ky.tri","Kyrgyz")) return false;
	//if(!LoadFile("trigrams/mk.tri","Macedonian")) return false;
	//if(!LoadFile("trigrams/mn.tri","Mongolian")) return false;
	if(!LoadFile(pathName, "ru.tri","ru")) return false;
	if(!LoadFile(pathName, "sr.tri","sr")) return false;
	if(!LoadFile(pathName, "uk.tri","uk")) return false;
	if(!LoadFile(pathName, "uz.tri","uz")) return false;
                            
	if(!LoadFile(pathName, "af.tri","af")) return false;
	if(!LoadFile(pathName, "az.tri","az")) return false;
	if(!LoadFile(pathName, "cs.tri","cs")) return false;
	if(!LoadFile(pathName, "da.tri","da")) return false;
	if(!LoadFile(pathName, "de.tri","de")) return false;
	if(!LoadFile(pathName, "en.tri","en")) return false;
	if(!LoadFile(pathName, "es.tri","es")) return false;
	if(!LoadFile(pathName, "fi.tri","fi")) return false;
	if(!LoadFile(pathName, "fr.tri","fr")) return false;
	if(!LoadFile(pathName, "hi.tri","hi")) return false;
	if(!LoadFile(pathName, "hr.tri","hr")) return false;
	if(!LoadFile(pathName, "hu.tri","hu")) return false;
	if(!LoadFile(pathName, "id.tri","id")) return false;
	if(!LoadFile(pathName, "it.tri","it")) return false;
	if(!LoadFile(pathName, "lt.tri","lt")) return false;
	if(!LoadFile(pathName, "ne.tri","ne")) return false;
	if(!LoadFile(pathName, "nl.tri","nl")) return false;
	if(!LoadFile(pathName, "pl.tri","pl")) return false;
	if(!LoadFile(pathName, "pt.tri","pt")) return false;
	if(!LoadFile(pathName, "ro.tri","ro")) return false;
	if(!LoadFile(pathName, "sk.tri","sk")) return false;
	if(!LoadFile(pathName, "so.tri","so")) return false;
	if(!LoadFile(pathName, "sq.tri","sq")) return false;
	if(!LoadFile(pathName, "sv.tri","sv")) return false;
	if(!LoadFile(pathName, "sw.tri","sw")) return false;
	if(!LoadFile(pathName, "tl.tri","tl")) return false;
	if(!LoadFile(pathName, "tr.tri","tr")) return false;
	
	return true;
}

