//
//  Sorting.cpp
//  DSA
//
//  Created by Shivakiran Ayyagari on 4/13/19.
//  Copyright © 2019 Shivakiran Ayyagari. All rights reserved.
//

#include <stdio.h>
#include "Sorting.h"

void InHouseSorting::sorting::VectorForSorting(std::vector<int> &nums)
{
    nums.clear();
    nums.push_back(10);
    nums.push_back(3);
    nums.push_back(7);
    nums.push_back(4);
    nums.push_back(98);
}


void InHouseSorting::sorting::InsertionSort(std::vector<int> &nums)
{
    for(int i=0;i<nums.size();i++)
    {
        int temp=nums[i];
        int j=i;
        while(j>0 && temp<nums[j-1])
        {
            nums[j]=nums[j-1];
            j=j-1;
        }
        
        nums[j]=temp;
    }
}



void InHouseSorting::sorting::MergeSort(std::vector<int> &nums)
{
    unsigned long startIdx=0;
    auto endIdx=nums.size()-1;
    pMergeSort(nums,startIdx,endIdx);
}


//private methods
void InHouseSorting::sorting::pMergeSort(std::vector<int> &nums, unsigned long strIdx, unsigned long endIdx)
{
    if(strIdx<endIdx)
    {
        unsigned long mid= strIdx+(endIdx-strIdx)/2;
        
        pMergeSort(nums, strIdx, mid);
        pMergeSort(nums, mid+1, endIdx);
        pMerge(nums,strIdx,mid,endIdx);
        
    }
}
void InHouseSorting::sorting::pMerge(std::vector<int> &nums, unsigned long strIdx, unsigned long mid, unsigned long endIdx)
{
    int temp[endIdx-strIdx+1];
    auto i=strIdx;
    auto j=mid+1;
    auto k=0;
    
    while(i<=mid&&j<=endIdx)
    {
        if(nums[i]<=nums[j])
        {
            temp[k]=nums[i];
            k++;
            i++;
        }
        else
        {
            temp[k]=nums[j];
            k++;
            j++;
        }
    }
    
    // add elements left in the first interval
    while(i <= mid) {
        temp[k] = nums[i];
        k += 1; i += 1;
    }
    
    // add elements left in the second interval
    while(j <= endIdx) {
        temp[k] = nums[j];
        k += 1; j += 1;
    }
    
    // copy temp to original interval
    for(auto i = strIdx; i <= endIdx; i += 1) {
        nums[i] = temp[i - strIdx];
    }
}
