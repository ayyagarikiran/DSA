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


class Node
{
public:
	int data;
	Node *next;
};

struct Node *newNode(int data)
{
	Node *temp=new Node;
	temp->data=data;
	temp->next=NULL;
	return temp;
}

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


//----------------------LinkedLists Implementation--------//
void removeDups(Node *start)
{
	std::unordered_set<int> seen;
	
	Node *curr=start;
	Node *prev=NULL;
	
	while(curr!=NULL)
	{
		if(seen.find(curr->data)!=seen.end())
		{
			prev->next=curr->next;
			delete (curr);
		}
		else
		{
			seen.insert(curr->data);
			prev=curr;
		}
		curr=prev->next;
	}
	
}

void printList(Node *start)
{
	while(start!=NULL)
	{
		std::cout<<start->data<<" ";
		start=start->next;
	}
	std::cout<<"\n";
}


void CTCILinkedLists::removeDuplicates()
{
	
	Node *start = newNode(10);
	start->next = newNode(12);
	start->next->next = newNode(11);
	start->next->next->next = newNode(11);
	start->next->next->next->next = newNode(12);
	start->next->next->next->next->next =newNode(11);
	start->next->next->next->next->next->next =newNode(10);
	
	printList(start);
	removeDups(start);
	printList(start);
	
}
//---------kthToLast------------------//

int CTCILinkedLists::kthToLast(int &num)
{
	Node *start = newNode(10);
	start->next = newNode(12);
	start->next->next = newNode(13);
	start->next->next->next = newNode(14);
	start->next->next->next->next = newNode(15);
	start->next->next->next->next->next =newNode(16);
	start->next->next->next->next->next->next =newNode(17);
	
	Node * countList=start;
	int cnt=0;
	while(countList!=NULL)
	{
			cnt++;
		countList=countList->next;
	}
	int cnt2=0;
	while(start!=NULL)
	{
		if(cnt2==(cnt-1-num))
			return start->data;
		cnt2++;
		start=start->next;
	}
	return 0;
}
//----delete middle element-------//

void CTCILinkedLists::deleteMiddleElement()
{
	Node *start = newNode(10);
	start->next = newNode(12);
	start->next->next = newNode(13);
	start->next->next->next = newNode(14);
	start->next->next->next->next = newNode(15);
	start->next->next->next->next->next =newNode(16);
	start->next->next->next->next->next->next =newNode(17);
	
	printList(start);
	
	Node *slowPtr=start;
	Node *fastPtr=start;
	Node *prev=NULL;
	if(start==NULL)
		return;
	//should return
	
	if(start->next==NULL)
		return;
	while(fastPtr!=NULL && fastPtr->next!=NULL)
	{
		fastPtr=fastPtr->next->next;
		prev=slowPtr;
		slowPtr=slowPtr->next;
	}
	
	prev->next=slowPtr->next;
	delete slowPtr;
	
	printList(start);
}

void CTCILinkedLists::partition(int x)
{
	Node *start = newNode(10);
	start->next = newNode(12);
	start->next->next = newNode(24);
	start->next->next->next = newNode(1);
	start->next->next->next->next = newNode(15);
	start->next->next->next->next->next =newNode(3);
	start->next->next->next->next->next->next =newNode(17);
	
	printList(start);
	
	Node *smallerThanHead=NULL;
	Node *smallerLast=NULL;
	Node *greaterEqualHead=NULL;
	Node *greaterEqualLast=NULL;
	
	while(start!=NULL)
	{
		if(start->data<x)
		{
			if(smallerThanHead==NULL)
			{
				smallerLast=smallerThanHead=start;
			}
			else
			{
				smallerLast->next=start;
				smallerLast=start;
				
			}
		}
		else
		{
			if(greaterEqualHead==NULL)
			{
				greaterEqualLast=greaterEqualHead=start;
			}
			else
			{
				greaterEqualLast->next=start;
				greaterEqualLast=start;
			}
		}
		start=start->next;
	}
	if (greaterEqualLast != NULL)
		greaterEqualLast->next = NULL;
	if(smallerLast==NULL)
	{
		printList(greaterEqualLast);
	}
	else if(greaterEqualLast==NULL)
	{
		printList(smallerLast);
	}
	else
	{
		smallerLast->next=greaterEqualHead;
		printList(smallerThanHead);
	}
	
}

void CTCILinkedLists::addTwoLinkedLists()
{
	Node *firstList=newNode(1);
	firstList->next = newNode(2);
	firstList->next->next = newNode(4);
	firstList->next->next->next = newNode(6);
	
	Node *secondList=newNode(3);
	secondList->next = newNode(2);
	secondList->next->next = newNode(6);
	secondList->next->next->next = newNode(1);
	
	Node *temp=NULL;
	Node *prev=NULL;
	Node *res=NULL;
	int carryOver=0;
	int sum=0;
	while(firstList!=NULL || secondList!=NULL)
	{
		sum=carryOver+(firstList->data+secondList->data);
		carryOver=sum/10;
		
		temp=newNode(sum%10);
		if(res==NULL)
			res=temp;
		else
			prev->next=temp;
		prev=temp;
		
		if(firstList)
			firstList=firstList->next;
		if(secondList)
			secondList=secondList->next;
	}
	
	printList(res);
}


bool CTCILinkedLists::Palindrome()
{
	Node *head=newNode(2);
	head->next = newNode(4);
	head->next->next = newNode(4);
	head->next->next->next = newNode(2);
	
	Node *slow=head, *fast=head, *prev=nullptr, *next=slow;
	while(fast && fast->next) {
		fast=fast->next->next;
		slow = slow->next;
	}
	while(slow) {
		next = slow->next;
		slow->next=prev;
		prev=slow;
		slow=next;
	}
	while(prev && head)
	{
		if(prev->data != head->data) {
			return false;
		}
		prev=prev->next;
		head = head->next;
	}
	
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

