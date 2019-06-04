//
//  CTCI.h
//  DSA
//
//  Created by Shivakiran Ayyagari on 5/24/19.
//  Copyright © 2019 Shivakiran Ayyagari. All rights reserved.
//

#ifndef CTCI_h
#define CTCI_h
#include <vector>
#include <string>

#define matSize 4;

typedef std::string string_t;

class CTCIArrayAndStrings
{
public:
    CTCIArrayAndStrings(){}
    ~CTCIArrayAndStrings();
public:
    bool isUnique(string_t &s);
    bool checkPermutation(string_t &s,string_t &t);
    void URLify(string_t &s,int length);
    bool palindromePermutation(string_t &s);
    bool oneAway(string_t &s,string_t &t);
    string_t stringCompression(string_t &s);
    void rotateMatrix();
    bool stringRotation(string_t &s, string_t &t);
private:
    bool oneEditReplace(string_t &s, string_t &t);
};

class CTCILinkedLists
{
public:
    CTCILinkedLists(){}
    ~CTCILinkedLists();
public:
    void removeDuplicates();
    int kthToLast(int &num);
    void deleteMiddleElement();
    void partition(int x);
    void addTwoLinkedLists();
    bool Palindrome();
    
};



#endif /* CTCI_h */
