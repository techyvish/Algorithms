//
//  ZigZag.cpp
//  AlgorithmTutorials
//
//  Created by Vishal Patel on 7/6/14.
//  Copyright (c) 2014 Vishal. All rights reserved.
//

//Problem Statement for ZigZag
//
//
//Problem Statement
//
//A sequence of numbers is called a zig-zag sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a zig-zag sequence.
//
//For example, 1,7,4,9,2,5 is a zig-zag sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, 1,4,7,2,5 and 1,7,4,5,5 are not zig-zag sequences, the first because its first two differences are positive and the second because its last difference is zero.
//
//Given a sequence of integers, sequence, return the length of the longest subsequence of sequence that is a zig-zag sequence. A subsequence is obtained by deleting some number of elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.
//
//
//Definition
//
//Class:	ZigZag
//Method:	longestZigZag
//Parameters:	int[]
//Returns:	int
//Method signature:	int longestZigZag(int[] sequence)
//(be sure your method is public)
//
//
//Constraints
//-	sequence contains between 1 and 50 elements, inclusive.
//-	Each element of sequence is between 1 and 1000, inclusive.
//
//Examples
//0)
//
//{ 1, 7, 4, 9, 2, 5 }
//Returns: 6
//The entire sequence is a zig-zag sequence.
//1)
//
//{ 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 }
//Returns: 7
//There are several subsequences that achieve this length. One is 1,17,10,13,10,16,8.
//2)
//
//{ 44 }
//Returns: 1
//3)
//
//{ 1, 2, 3, 4, 5, 6, 7, 8, 9 }
//Returns: 2
//4)
//
//{ 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 }
//Returns: 8
//5)
//
//{ 374, 40, 854, 203, 203, 156, 362, 279, 812, 955,
//    600, 947, 978, 46, 100, 953, 670, 862, 568, 188,
//    67, 669, 810, 704, 52, 861, 49, 640, 370, 908,
//    477, 245, 413, 109, 659, 401, 483, 308, 609, 120,
//    249, 22, 176, 279, 23, 22, 617, 462, 459, 244 }
//Returns: 36
//This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2010, TopCoder, Inc. All rights reserved.
//
//
//
//
//This problem was used for:
//TopCoder Collegiate Challenge Semifinal Round 3 - Division I, Level One

#include <cstdio>

#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>
#include <unistd.h>
#include <climits>

using namespace std;

typedef enum  {
    POSITIVE = 1,
    NEGATIVE = -1,
    ZERO = 0,
    START = INT_MAX,
} STATUS;

struct element
{
    int lzValue;
    STATUS status;
};

class ZigZag {
    
    vector <element> v;

public:

    int length;
    
    int  longestZigZag(int sequence[])
    {
        element e;
        e.lzValue = 1;
        e.status = START;
        
        v.push_back(e);
        vector<element>::iterator it;
       
        
        for ( int  i = 1 ; i < length ; i++ )
        {
            it = v.begin();
            int max = INT_MIN;
            element p;
            element selected;
            for ( int j = 0 ; j < i ; j++ )
            {
                element e = *it;
                
                cout << sequence[i] << " - " << sequence[j] << endl;
                if ( (sequence[i] - sequence[j]) > 0 )
                {
                
                  if ( e.status == START || e.status == NEGATIVE )
                  {
                      p.status = POSITIVE;
                      p.lzValue =  e.lzValue + 1;
                     
                  }
                }
                else if ( (sequence[i] - sequence[j]) < 0 )
                {
                    if ( e.status == START || e.status == POSITIVE )
                    {
                        p.status = NEGATIVE;
                        p.lzValue =  e.lzValue + 1;

                    }
                }
                else
                {
                    
                }
                
                if ( max < p.lzValue )
                {
                    max = p.lzValue;
                    selected = p;
                }
                it++;
            }
            
            v.push_back(selected);
            cout << "-----------------" << endl;
        }
        
        return (*it).lzValue;
    }
};

//int main()
//{
//    //int seq[] = { 1, 7, 4, 9, 2, 5 };
//    //int seq[] = { 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 };
//    //int seq[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//    //int seq[] = {70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32};
//    int seq[] = {374, 40, 854, 203, 203, 156, 362, 279, 812, 955,
//                 600, 947, 978, 46, 100, 953, 670, 862, 568, 188,
//                 67, 669, 810, 704, 52, 861, 49, 640, 370, 908,
//                 477, 245, 413, 109, 659, 401, 483, 308, 609, 120,
//                 249, 22, 176, 279, 23, 22, 617, 462, 459, 244 };
//    ZigZag z;
//    z.length = sizeof(seq)/sizeof(seq[0]);
//    int length = z.longestZigZag(seq);
//    cout << length;
//    return 0;
//}
