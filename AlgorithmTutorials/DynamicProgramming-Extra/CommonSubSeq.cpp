//
//  CommonSubSeq.cpp
//  AlgorithmTutorials
//
//  Created by Vishal Patel on 23/07/2014.
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

using namespace std;

#define NMAX 50

typedef vector<int> VI ; typedef vector<vector<int>> VVI;
typedef vector<string> VS; typedef vector<vector<string>> VVS;
typedef signed long long i64; typedef unsigned long long u64;

class CommonSubsequence {
    

public:
    
    int findCommonSubSequence(string str1,int m ,string str2, int n,vector<char>& arr)
    {
        cout << str1[m] << " " << str2[n] << endl;
        if ( m == 0 || n == 0 )
            return 0;
        
        if ( str1[m-1] == str2[n-1])
        {
            arr.push_back(str1[m-1]);
            return  findCommonSubSequence(str1, m-1, str2, n-1,arr) + 1;    
        }
        else
        {
            return  max( findCommonSubSequence(str1, m-1, str2, n,arr) , findCommonSubSequence(str1, m, str2, n-1,arr));
        }
    }
};

//int main()
//{
//    string str1 =  "AG";
//    string  str2 =   "DAGP";
//    CommonSubsequence s;
//    vector<char> arr;
// int n = s.findCommonSubSequence(str1, str1.length() , str2 , str2.length() ,arr);
//    cout << n << endl;
//}