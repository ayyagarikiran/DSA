//
//  main.cpp
//  DSA
//
//  Created by Shivakiran Ayyagari on 4/8/19.
//  Copyright © 2019 Shivakiran Ayyagari. All rights reserved.
//

#include <iostream>
#include <math.h>

#include "leetcode.h"
#include "Sorting.h"
#include "CTCI.h"

Arrays *Array;
CTCIArrayAndStrings *CTCIArraysAndString;

int main(int argc, const char * argv[]) {
    // insert code here..
    std::vector<int> res;
    std::vector<int>nums;
    
    
    //----- Two sum---------//
    int target=9;
    Array->TestCasesTwoSum(nums);
    res= Array->TwoSum(nums, target);
    std::cout<<"Check if there exists a twosum and also find the positions of it"<<std::endl;
    for(auto &it:res)
        std::cout<<it<<" ";
    //---------------------//
    
    //----- Reverse Integer---//
    int rev=Array->ReverseInteger(2341);
    std::cout<<"\n";
    std::cout<<"Reverse Integer "<<rev<<std::endl;
    //------------------------//
    
    //------IsPalindrome-----//
    bool palindrome=Array->IsPalindrome(2020201);
    std::cout<<"\n";
    std::cout<<"to check if the number is palindorme or not "<<palindrome<<std::endl;
    //-----------------------//
    
    //-----Search Insert-----//
    auto idx=Array->searchInsert(nums, 7);
    std::cout<<"\n";
    std::cout<<"The value is at idx  "<<idx<<std::endl;
    
    //----length of last word in the string--//
    std::string S ="Hello World ";
    auto cnt=Array->lengthOfLastWord(S);
    std::cout<<"\n";
    std::cout<<"length of last word is "<<cnt<<std::endl;
    std::cout<<"\n";
    
    //----Plus one in the vector-----//
    std::vector<int> numsOnePlus;
    Array->TestCasesPlusOne(numsOnePlus);
    Array->plusOne(numsOnePlus);
    std::cout<<"One plus:  ";
    for(auto et:numsOnePlus)
        std::cout<<et<<" ";
    std::cout<<"\n";
    
    //-----SingleNumber-------//
    std::cout<<"\n";
    std::vector<int> numsSingleNumber;
    Array->TestCasesSingleNumber(numsSingleNumber);
    int sNumber=Array->singleNumber(numsSingleNumber);
    std::cout<<"Single Number: "<<sNumber<<std::endl;
    
    //----majority number----//
    std::cout<<"\n";
    std::vector<int> numsMajorityNumber;
    Array->TestCasesMajorityElement(numsMajorityNumber);
    int MajorityNumber=Array->majorityElement(numsMajorityNumber);
    std::cout<<"Majority Number: "<<MajorityNumber<<std::endl;
    
    //----valid anagram---//
    std::cout<<"\n";
    std::string s="anagram";
    std::string t="nagram";
    bool Anagram=false;
    Anagram=Array->isAnagram(s, t);
    std::cout<<"is Anagram: "<<Anagram<<std::endl;
    
    //----power of two---//
    std::cout<<"\n";
    bool powerOfTwo=false;
    int numberPowerOfTwo=8;
    powerOfTwo=Array->powerOfTwo(numberPowerOfTwo);
    std::cout<<"Is Power of Two? "<<powerOfTwo<<std::endl;
    
    //----counting number of bits----//
    std::cout<<"\n";
    uint32_t numberCountingBits=static_cast<uint32_t>(00000000000000000000000000011011);
    int numBit=Array->numberOfOneBits(numberCountingBits);
    std::cout<<"No of One Bits: "<<numBit<<std::endl;
    
    //----power of threee------//
    std::cout<<"\n";
    int numberPowerOfThree=27;
    bool isPowerOfThree=false;
    isPowerOfThree=Array->powerOfThree(numberPowerOfThree);
    std::cout<<"Is Power of three? "<<isPowerOfThree<<std::endl;
    
    
    //----Sorting an array------//
    InHouseSorting::sorting::VectorForSorting(nums);
    
    //insertion sort
    //sorts->InsertionSort(nums);
    
    //merge sort
    
    InHouseSorting::sorting::MergeSort(nums);
    std::cout<<"\n";
    for(auto &it:nums)
    {
        std::cout<<it<<" ";
    }
    std::cout<<"\n";
    
    
    //-----------------CTCI------------------------------------//
    
    //---Arrays And Strings-----------//
    
    //---IsUnique-----//
    std::string isUniqueString="abccd";
    bool isUnique=CTCIArraysAndString->isUnique(isUniqueString);
    std::cout<<"\n";
    std::cout<<"Is the string unique ";
    std::cout<<isUnique<<std::endl;
    
    //--checkPermutation----//
    
    std::string checkPermuString1="dog";
    std::string checkPermuString2="gdd";
    bool checkPermutation=CTCIArraysAndString->checkPermutation(checkPermuString1, checkPermuString2);
    std::cout<<"\n";
    std::cout<<"Check Permuation ";
    std::cout<<checkPermutation<<std::endl;
    
    //----URLIFY---------//
    
    //---PalindromePermutation------//
    std::string palPermString="Tact Coa";
    bool isPalPerm=CTCIArraysAndString->palindromePermutation(palPermString);
    std::cout<<"\n";
    std::cout<<"Palindrome Permutation ";
    std::cout<<isPalPerm<<std::endl;
    
    //----OneEditDistance--------//
    std::string oneEditString1="pale";
    std::string oneEditString2="ple";
    bool isOneEditDistance=CTCIArraysAndString->oneAway(oneEditString1,oneEditString2);
    std::cout<<"\n";
    std::cout<<"One Away ";
    std::cout<<isOneEditDistance<<std::endl;
    
    //------String Compression--------/
    std::string stringCompString="aabcccccaaa";
    std::string compString;
    compString=CTCIArraysAndString->stringCompression(stringCompString);
    std::cout<<compString<<std::endl;
    return 0;
}


