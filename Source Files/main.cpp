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

Arrays *Array;
InHouseSorting::sorting *sorts;

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
    bool Anagram;
    Anagram=Array->isAnagram(s, t);
    std::cout<<"is Anagram: "<<Anagram<<std::endl;
    
    //----Sorting an array------//
    sorts->VectorForSorting(nums);
    
    //insertion sort
    //sorts->InsertionSort(nums);
    
    //merge sort
    
    sorts->MergeSort(nums);
    std::cout<<"\n";
    for(auto &it:nums)
    {
        std::cout<<it<<" ";
    }
    std::cout<<"\n";
    
    return 0;
}
