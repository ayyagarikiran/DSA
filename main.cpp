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
    int rev=Array->ReverseInteger(pow(2,31)-1);
    std::cout<<"\n";
    std::cout<<"Reverse Integer"<<std::endl;
    std::cout<<rev<<std::endl;
    //------------------------//
    
    //------IsPalindrome-----//
    bool palindrome=Array->IsPalindrome(2020201);
    
    std::cout<<"to check if the number is palindorme or not "<<palindrome<<std::endl;
    //-----------------------//
    
    //----Sorting an array------//
    InHouseSorting::VectorForSorting(nums);
    InHouseSorting::InsertionSort(nums);
    
    for(auto &it:nums)
    {
        std::cout<<it<<" ";
    }
    std::cout<<"\n";
    return 0;
}
