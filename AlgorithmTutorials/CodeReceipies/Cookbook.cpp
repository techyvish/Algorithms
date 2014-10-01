//
//  Cookbook.cpp
//  AlgorithmTutorials
//
//  Created by Vishal Patel on 17/09/2014.
//  Copyright (c) 2014 Vishal. All rights reserved.
//
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
#include <list>
#include <string>
#include <map>
#include <set>
#include <x86intrin.h>

using namespace std;

#define NMAX 50

typedef vector<int> VI ; typedef vector<vector<int>> VVI;
typedef vector<string> VS; typedef vector<vector<string>> VVS;
typedef signed long long i64; typedef unsigned long long u64;

class Cookbook {
    
    
public:
    
    bool isPowerOf2(int x)
    {
        
        int y = ( x << 31);
        cout << y ;
        return y  == 0;
    }
    
    void countbits()
    {
       // count = __builtin_popcount(32);
    }
    
    void generateSubsets()
    {
        
    }
    
};


//int main()
//{
//    Cookbook *instance = new Cookbook();
//    cout << instance->isPowerOf2(1) << endl;
//    
//    
//    return 0;
//}
