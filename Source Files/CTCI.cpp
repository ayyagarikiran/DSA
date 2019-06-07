//
//  CTCI.cpp
//  DSA
//
//  Created by Shivakiran Ayyagari on 5/24/19.
//  Copyright © 2019 Shivakiran Ayyagari. All rights reserved.
//

#include <stdio.h>
#include <iostream>

#include "CTCI.h"


#include <unordered_map>
#include <map>
#include <unordered_set>




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
	int nSpaces=0;
	for(int i =0;i<length;i++)
	{
		if(str[i]==' ')
			nSpaces++;
	}
	int totLength=length-nSpaces+nSpaces*3;
	
	while(totLength>0)
	{
		if(str[length-1]!=' ')
		{
			str[totLength-1]=str[length-1];
			totLength--;
			length--;
		}
		else
		{
			str[totLength-1]='0';
			str[totLength-2]='2';
			str[totLength-3]='%';
			totLength-=3;
			length--;
		}
	}
}
void CTCIArrayAndStrings::rotateMatrix()
{
	int mat[4][4] =
	{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};
	int N=4;
	for (int x = 0; x < N / 2; x++)
	{
		// Consider elements in group of 4 in
		// current square
		for (int y = x; y < N-x-1; y++)
		{
			// store current cell in temp variable
			int temp = mat[x][y];
			
			// move values from right to top
			mat[x][y] = mat[y][N-1-x];
			
			// move values from bottom to right
			mat[y][N-1-x] = mat[N-1-x][N-1-y];
			
			// move values from left to bottom
			mat[N-1-x][N-1-y] = mat[N-1-y][x];
			
			// assign temp to left
			mat[N-1-y][x] = temp;
		}
	}
	
	for(int i =0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			std::cout<<mat[i][j]<<" ";
		}
		std::cout<<"\n";
		
	}
	
}

void CTCIArrayAndStrings::ZeroMatrix()
{
	int mat[4][4] =
	{
		{1, 2, 4, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 0},
		{13, 14, 15, 16}
	};
	std::vector<int> row,col;
	
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(mat[i][j]==0)
			{
				row.push_back(i);
				col.push_back(j);
			}
		}
	}
	
	for(int i =0;i<row.size();i++)
	{
		for(int j=0;j<4;j++)
			mat[row[i]][j]=0;
	}
	
	for(int i =0;i<col.size();i++)
	{
		for(int j=0;j<4;j++)
			mat[j][col[i]]=0;
	}
	
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			std::cout<<mat[i][j]<<" ";
		}
		std::cout<<"\n";
	}
	
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

bool CTCIArrayAndStrings::stringRotation(string_t &string1, string_t &string2)
{
	if(string1.size()!=string2.size())
		return false;
	string_t start="", end="";
	string_t full="";
	for(int i=0;i<string1.size();i++)
	{
		if(string1[i]==string2[0])
			end+=string2[0];
		else
			start+=string2[i];
	}
	full=start+end;
	if(string1.compare(full)!=0)
		return false;
	else
		return true;
}


//----------------------private methods---------------//
//----------------------Private Methods---------------//

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

