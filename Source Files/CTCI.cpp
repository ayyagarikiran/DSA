//
//  CTCI.cpp
//  DSA
//
//  Created by Shivakiran Ayyagari on 5/24/19.
//  Copyright © 2019 Shivakiran Ayyagari. All rights reserved.
//

#include <stdio.h>
#include "CTCI.h"
#include <unordered_map>
#include <map>


bool CTCIArrayAndStrings::isUnique(string_t &str)
{
    std::unordered_map<char,int> uniqueChars;
    
    for(auto &s:str)
    {
        if(uniqueChars.find(s)!=uniqueChars.end())
            return false;
        uniqueChars[s]+=1;
    }
    return true;
}

bool CTCIArrayAndStrings::checkPermutation(string_t &string1, string_t &string2)
{
    std::unordered_map<char,int> stringMap1,stringMap2;
    if(string1.size()!=string2.size())
        return false;
    for(auto &s:string1)
    {
        stringMap1[s]+=1;
    }
    for(auto &s:string2)
    {
        stringMap2[s]+=1;
    }
	for(auto &entity:stringMap1)
	{
		if(stringMap2.find(entity.first)==stringMap2.end())
			return false;
		if(entity.second!=stringMap2[entity.first])
			return false;
	}
    return true;
}

void CTCIArrayAndStrings::URLify(string_t &str,int length)
{
	
}

bool CTCIArrayAndStrings::palindromePermutation(string_t &str)
{
	std::unordered_map<char,int> palPerm;
	for(auto &s:str)
	{
		if(s>='A' && s<='Z')
			s=s+'z'-'Z';
		if(s!=' ')
			palPerm[s]++;
	}
	int pvOddLetter=0;
	for(auto &entity:palPerm)
	{
		if(entity.second%2!=0)
		{
			if(pvOddLetter)
				return false;
			pvOddLetter++;
		}
	}
	return true;
}

bool CTCIArrayAndStrings::oneAway(string_t &string1, string_t &string2)
{
	if(string1.size()==string2.size())
		return oneEditReplace(string1,string2);
	
	else if(string1.size()+1==string2.size())
		return oneEditReplace(string1,string2);
	
	else if(string1.size()-1==string2.size())
		
		return oneEditReplace(string2,string1);
	else
		return false;
	
}

//private methods

bool CTCIArrayAndStrings::oneEditReplace(string_t &string1,string_t &string2)
{
	bool pvFoundDifference=false;
	for(int i=0;i<string1.size();i++)
	{
		if(string1[i]!=string2[i])
		{
			if(pvFoundDifference)
				return false;
			
			pvFoundDifference=true;
		}
	}
	return true;
}


string_t CTCIArrayAndStrings::stringCompression(string_t &str)
{
	string_t pvCompressedString;
	std::map<char,int> compressedStringMap;
	// aabcccccaaa
	for(auto &s:str)
		compressedStringMap[s]+=1;
	
	char c=str[0];
	int cnt=1;
	for(int i=1;i<str.size();i++)
	{
		if(c==str[i])
			cnt++;
		else
		{
			pvCompressedString.push_back(c);
			pvCompressedString.push_back('0'+cnt);
			cnt=1;
			c=str[i];
		}
	}
	pvCompressedString.push_back(c);
	pvCompressedString.push_back('0'+cnt);
	
	
	if(pvCompressedString.size()<str.size())
		return pvCompressedString;
	else
		return str;
}
