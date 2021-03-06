//
//  leetcode.cpp
//  DSA
//
//  Created by Shivakiran Ayyagari on 4/11/19.
//  Copyright © 2019 Shivakiran Ayyagari. All rights reserved.
//

#include <stdio.h>
#include <unordered_map>
#include <map>

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
    for(int i=0;i < nums.size(); i++)
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
void Arrays::plusOne(std::vector<int> &nums)
{
    int carry=0;
    unsigned long nSize=nums.size()-1;
    
    if(nums.size())
    {
        nums[nSize]+=1;
        carry=nums[nSize]/10;
        nums[nSize]%=10;
        
        for(int i=nSize-1;i>=0;i--)
        {
            nums[i]=nums[i]+carry;
            carry=nums[i]/10;
            nums[i]%=10;
        }

        if(carry>0)
        {
            std::vector<int>::iterator it;
            it=nums.begin();
            nums.insert(it,carry);
        }
    }
}

int Arrays::singleNumber(std::vector<int> &nums)
{
    int sNumber=0;
    for(auto &entitiy:nums)
        sNumber^=entitiy;
    return sNumber;
}

int Arrays::majorityElement(std::vector<int> &nums)
{
    //assuming there is alwatys a max number;
    std::unordered_map<int,int> elementCount;
    for(auto &num:nums)
    {
        elementCount[num]+=1;
        if(elementCount[num]>nums.size()/2)
            return num;
    }
    
    return 0;
}

bool Arrays::isAnagram(std::string &S, std::string &T)
{
    if(S.size()!=T.size())
        return false;
    std::map<char,int> mapS;
    std::map<char,int> mapT;
    
    for(auto &s:S)
        mapS[s]+=1;
    for(auto &t:T)
        mapT[t]+=1;
    std::map<char,int> ::iterator it;
    for(it=mapS.begin();it!=mapS.end();it++)
    {
        
        if(mapT.find(it->first)==mapT.end())
            return false;
        else if(it->second!=mapT[it->first])
            return false;
        
    }
    return true;
}

bool Arrays::powerOfTwo(int &number)
{
    if(number>pow(2,31)-1)
        return false;
    if(number<=0)
        return false;
    if((number&(number-1))!=0)
        return false;
    
    return true;
        
}

int Arrays::numberOfOneBits(uint32_t &number)
{
    int count=0;
    while(number>static_cast<uint32_t>(0))
    {
        number=number&(number-1);
        count++;
    }
    return count;
}

bool Arrays::powerOfThree(int &number)
{
    if(number<1)
        return false;
    while(number>1)
    {
        if(number%3!=0)
            return false;
        number/=3;
    }
    return true;
}

//test cases
void Arrays::TestCasesTwoSum(std::vector<int> &nums)
{
    nums={2,4,7,11};
}

void Arrays::TestCasesPlusOne(std::vector<int> &nums)
{
    nums={9,9,9,9,9};
}

void Arrays::TestCasesSingleNumber(std::vector<int> &nums)
{
    nums={1,2,2,3,1,4,4};
}

void Arrays::TestCasesMajorityElement(std::vector<int> &nums)
{
    nums={2,2,1,1,1,2,2};
}
