//
//  CTCIBitManipulation.h
//  DSA
//
//  Created by Shivakiran Ayyagari on 6/6/19.
//  Copyright © 2019 Shivakiran Ayyagari. All rights reserved.
//

#ifndef CTCIBitManipulation_h
#define CTCIBitManipulation_h



class CTCIBitManipulation:
{
public:
    CTCTIBitManipulation();
    ~CTCIBitManipulation();
public:
    void insertion(int M,int N,int i,int j);
private:
    //helper functions
    //getbit
    int GetBit(int num, int position);
    int SetBit(int num, int position);
    int clearBit(int num, int position);
}

#endif /* CTCIBitManipulation_h */
