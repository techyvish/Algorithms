//
//  SubSetSum.cpp
//  AlgorithmTutorials
//
//  Created by Vishal Patel on 22/07/2014.
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

class SubSetSum {

public:
  
    bool subSetSumExist(vector<int> set, int sum,int n)
    {
        if ( sum == 0 )
            return true;
        if ( sum != 0 &&  n == 0 )
            return false;
        
        if ( set[n-1] >  sum )
            return subSetSumExist(set,sum,n-1);
        
        bool a =  subSetSumExist(set,sum,n-1);
        bool b = subSetSumExist(set,sum - set[n-1], n-1);
        return a || b;
    }
};

//int main()
//{
//    SubSetSum s;
//
//    VI v(5);
//    v = {3, 34, 4, 12, 5, 2};
//    int sum = 10 ;
//    cout << s.subSetSumExist(v,sum, 6) << endl;
//
//    return 0;
//}