//
//  Sorting.h
//  DSA
//
//  Created by Shivakiran Ayyagari on 4/13/19.
//  Copyright © 2019 Shivakiran Ayyagari. All rights reserved.
//

#ifndef Sorting_h
#define Sorting_h
#include <vector>

namespace InHouseSorting
{
    class sorting{
    public:
        //constructor
        sorting()
        {
            
        }
        
        //destructor
        ~sorting();
        
    public:
        static void InsertionSort(std::vector<int> &nums);
        static void MergeSort(std::vector<int> &nums);
        
    public:
        static void VectorForSorting(std::vector<int> &nums);
    private:
        static void pMergeSort(std::vector<int> &nums,unsigned long strIdx, unsigned long endIdx);
        static void pMerge(std::vector<int> &nums,unsigned long strIdx,unsigned long mid,unsigned long endIdx);

    };
}

#endif /* Sorting_h */
