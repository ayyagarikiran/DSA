//
//  leetcode.h
//  DSA
//
//  Created by Shivakiran Ayyagari on 4/11/19.
//  Copyright © 2019 Shivakiran Ayyagari. All rights reserved.
//

#ifndef leetcode_h
#define leetcode_h
#include <vector>
#include <string>

class Arrays
{
public:
    Arrays()
    {
    }
public:
    std::vector<int> TwoSum(std::vector<int> &nums, int target);
    int ReverseInteger(int num);
    bool IsPalindrome(int num);
    std::vector<int> RemoveElement(std::vector<int> &nums, int value);
    
public:
    //testcases
    void TestCasesTwoSum(std::vector<int> &nums);
};


#endif /* leetcode_h */
