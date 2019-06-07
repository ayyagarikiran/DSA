//
//  CTCIBitManipulation.cpp
//  DSA
//
//  Created by Shivakiran Ayyagari on 6/6/19.
//  Copyright © 2019 Shivakiran Ayyagari. All rights reserved.
//

#include <stdio.h>
#include "CTCIBitManipulation.h"
#include <iostream>
#include <bitset>

void CTCIBitManipulation::insertion(int M, int N, int i, int j)
{
    for(int k=i;k<=j;k++)
    {
        N=this->clearBit(N,k);
    }
    
    for(int k=0;k<i;k++)
    {
        M<<=1;
    }
    
    std::cout<<std::bitset<8>(M|N)<<std::endl;
}



//private helper methods
int CTCIBitManipulation::GetBit(int num, int position)
{
    return (num & 1<<position);
}

int CTCIBitManipulation::SetBit(int num, int position)
{
    return (num|1<<position);
}

int CTCIBitManipulation::clearBit(int num, int position)
{
    int mask=~(1<<position);
    return num&mask;
}


