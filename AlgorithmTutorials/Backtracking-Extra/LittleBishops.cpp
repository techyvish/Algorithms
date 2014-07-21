//
//  LittleBishops.cpp
//  AlgorithmTutorials
//
//  Created by Vishal Patel on 21/07/2014.
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

using namespace std;

struct _data
{
    
};

typedef struct _data data;

class LittleBishops {
    
    
public:
    
    bool finished = false;
    
    bool is_a_solution(int a[],int k, int n)
    {
        return ( k == n - 1 );
    }
    
    void process_solution(int a[],int k , int n)
    {
        
    }
    
    void construct_candidates(int a[],int k, int n, int c[], int *ncandidates)
    {
        
        for (int j = 0 ; j < n ; j++ )
        {
            for ( int i = 0 ; i < k ; i ++ )
            {
                if ( abs( a[i] - j ) != abs ( i - k ) )
                {
                    a[i] = j;
                }
            }
            
            c[*ncandidates] = j;
            *ncandidates = *ncandidates + 1;
        }
    }
    
    void backtrack(int a[],int k , int  n)
    {
        int c[NMAX];
        int ncandidates;
        int i ;
        
        if ( is_a_solution(a,k,n))
            process_solution(a,k,n);
        else
        {
            k = k+1;
            construct_candidates(a,k,n,c,&ncandidates);
            for ( i = 0 ; i < ncandidates ; i++ )
            {
                a[k] = c[i];
                backtrack(a,k,n);
                if ( finished )
                    return;
            }
        }
    }
    
    void placeTheBishops(int n )
    {
        int a[NMAX];  /* solution vector */
        backtrack(a,-1,n);
    }
};

int main()
{
    LittleBishops little;
    little.placeTheBishops(4);
    return 0;
}