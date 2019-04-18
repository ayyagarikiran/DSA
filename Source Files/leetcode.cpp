//
//  leetcode.cpp
//  DSA
//
//  Created by Shivakiran Ayyagari on 4/11/19.
//  Copyright © 2019 Shivakiran Ayyagari. All rights reserved.
//

#include <stdio.h>
#include <unordered_map>

#include "leetcode.h"



//two sum implementation
std::vector<int> Arrays::TwoSum(std::vector<int> &nums, int target)
{
    std::vector<int> result;
    std::unordered_map<int,int> hash_map;
    
    for(auto i=0;i<nums.size();i++)
    {
        int diff=target-nums[i];
        if(hash_map.find(diff)!=hash_map.end())
        {
            result.push_back(i);
            result.push_back(hash_map[diff]);
            break;
        }
        hash_map[nums[i]]=i;
    }
    
    return result;
}

//Reverse Integer Implementatin
int Arrays::ReverseInteger(int num)
{
    if((num>=pow(2,31)-1) || (num<=-pow(2,31)))
        return 0;
    int sign=1;
    if(num<0)
    {
        sign=-1;
        num*=-1;
    }
    int rev=0;
    while(num>0)
    {
        if(rev>(pow(2,31)-num%10)/10)
            return 0;
        rev=rev*10+num%10;
        num=num/10;
    }
    return rev;
}


//Ispalindrome Implementation
bool Arrays::IsPalindrome(int num)
{
    if(num<=0)
        return false;
    auto s=std::to_string(num);
    for(int i=0;i<s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-1-i])
            return false;
    }
    return true;
}


//remove element Implementation
std::vector<int> Arrays::RemoveElement(std::vector<int> &nums, int value)
{
    int pLength=0;
    for(int i; i < nums.size(); i++)
    {
        if(nums[i]!=value)
        {
            nums[pLength]=nums[i];
            pLength++;
        }
    }
    
    return nums;
    
}

unsigned long Arrays::searchInsert(std::vector<int> &nums, int target)
{
    auto ind=0;
    while(ind<nums.size())
    {
        if(nums.at(ind)==target)
            return ind;
        if(nums.at(ind)>target)
        {
            if(ind!=0)
                return ind;
            else
                return 0;
        }
        ind++;
    }
    return nums.size();
}

int Arrays::lengthOfLastWord(std::string &S)
{
    int cnt=0;
    for(auto &s:S)
    {
        if(s!=' ')
            cnt++;
        else if(cnt==0)
            continue;
        else
            break;
    }
    
    return cnt;
}
void Arrays::TestCasesTwoSum(std::vector<int> &nums)
{
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(7);
    nums.push_back(11);
}

