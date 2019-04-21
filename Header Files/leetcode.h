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
    
    ~Arrays();
    
public:
    std::vector<int> TwoSum(std::vector<int> &nums, int target);
    int ReverseInteger(int num);
    bool IsPalindrome(int num);
    std::vector<int> RemoveElement(std::vector<int> &nums, int value);
    unsigned long searchInsert(std::vector<int> &nums, int target);
    int lengthOfLastWord(std::string &S);
    void plusOne(std::vector<int> &nums);
    int singleNumber(std::vector<int> &nums);
    int majorityElement(std::vector<int> &nums);
    bool isAnagram(std::string &s, std::string &t);
    bool powerOfTwo(int &number);
    int numberOfOneBits(uint32_t &number);
    bool powerOfThree(int &number);
public:
    //testcases
    void TestCasesTwoSum(std::vector<int> &nums);
    void TestCasesPlusOne(std::vector<int> &nums);
    void TestCasesSingleNumber(std::vector<int> &nums);
    void TestCasesMajorityElement(std::vector<int> &nums);
};


#endif /* leetcode_h */
