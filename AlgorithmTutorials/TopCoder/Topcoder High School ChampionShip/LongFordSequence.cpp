//
//  File.cpp
//  AlgorithmTutorials
//
//  Created by Vishal Patel on 5/09/2014.
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
#include <string>

using namespace std;

#define NMAX 50

typedef vector<int> VI ; typedef vector<vector<int>> VVI;
typedef vector<string> VS; typedef vector<vector<string>> VVS;
typedef signed long long i64; typedef unsigned long long u64;

class LongFordSequence {


public:
    
    vector<int> getFirst(int *a,int total)
    {
        vector<int> arr(0);
        int j = 0 ;
        for ( int i = 0 ; i < 2 * total; i ++ )
        {
            if ( j ==  total)
                j = 0 ;
            arr.push_back(a[j++]);
        }
        int cnt =0 ;
        bool found = false;
        
        do
        {
            cnt = 0;
            found = false ;
//            for ( int i  = 0 ; i < arr.size(); i++ )
//                cout << arr[i] ;
//            cout << endl;
            for ( int i = 0 ; i < arr.size() ; i++ )
            {
                int p = arr[i] ;
                int q = arr[ i + p + 1];
                
                 if ( p != q )
                    break;
                 else {
                     cnt ++;
                 }
            }
            if ( cnt == total )
            {
                cout << "found";
                found = true;
                break;
            }
            
        } while (next_permutation(arr.begin(),arr.end())) ;
    
        if ( found )
            return arr ;
        else
            return vector<int> ();
    }
};


//int  main()
//{
//    LongFordSequence a;
//    int arr[] = {1,2,3};
//    int total = sizeof(arr)/sizeof(arr[0]);
//    vector<int> p = a.getFirst(arr,total);
//    return 0;
//}