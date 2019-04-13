//
//  Sorting.cpp
//  DSA
//
//  Created by Shivakiran Ayyagari on 4/13/19.
//  Copyright © 2019 Shivakiran Ayyagari. All rights reserved.
//

#include <stdio.h>
#include "Sorting.h"

void InHouseSorting::VectorForSorting(std::vector<int> &nums)
{
    nums.clear();
    nums.push_back(10);
    nums.push_back(3);
    nums.push_back(7);
    nums.push_back(4);
    nums.push_back(98);
}


void InHouseSorting::InsertionSort(std::vector<int> &nums)
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



void InHouseSorting::MergeSort(std::vector<int> &nums)
{
    
}
