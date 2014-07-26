//
//  Subsets.cpp
//  AlgorithmTutorials
//
//  Created by Vishal Patel on 7/10/14.
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

//>>>>>>>>1,0
//>>>>>>>>>>>>>>>>2,0
//>>>>>>>>>>>>>>>>>>>>>>>>3,0
//>>>>>>>>>>>>>>>>>>>>>>>>3,1
//>>>>>>>>>>>>>>>>>>>>>>>>3,2
//>>>>>>>>>>>>>>>>2,1
//>>>>>>>>>>>>>>>>>>>>>>>>3,0
//>>>>>>>>>>>>>>>>>>>>>>>>3,1
//>>>>>>>>>>>>>>>>>>>>>>>>3,2
//>>>>>>>>>>>>>>>>2,2
//>>>>>>>>>>>>>>>>>>>>>>>>3,0
//>>>>>>>>>>>>>>>>>>>>>>>>3,1
//>>>>>>>>>>>>>>>>>>>>>>>>3,2
//>>>>>>>>1,1
//>>>>>>>>>>>>>>>>2,0
//>>>>>>>>>>>>>>>>>>>>>>>>3,0
//>>>>>>>>>>>>>>>>>>>>>>>>3,1
//>>>>>>>>>>>>>>>>>>>>>>>>3,2
//>>>>>>>>>>>>>>>>2,1
//>>>>>>>>>>>>>>>>>>>>>>>>3,0
//>>>>>>>>>>>>>>>>>>>>>>>>3,1
//>>>>>>>>>>>>>>>>>>>>>>>>3,2
//>>>>>>>>>>>>>>>>2,2
//>>>>>>>>>>>>>>>>>>>>>>>>3,0
//>>>>>>>>>>>>>>>>>>>>>>>>3,1
//>>>>>>>>>>>>>>>>>>>>>>>>3,2
//>>>>>>>>1,2
//>>>>>>>>>>>>>>>>2,0
//>>>>>>>>>>>>>>>>>>>>>>>>3,0
//>>>>>>>>>>>>>>>>>>>>>>>>3,1
//>>>>>>>>>>>>>>>>>>>>>>>>3,2
//>>>>>>>>>>>>>>>>2,1
//>>>>>>>>>>>>>>>>>>>>>>>>3,0
//>>>>>>>>>>>>>>>>>>>>>>>>3,1
//>>>>>>>>>>>>>>>>>>>>>>>>3,2
//>>>>>>>>>>>>>>>>2,2
//>>>>>>>>>>>>>>>>>>>>>>>>3,0
//>>>>>>>>>>>>>>>>>>>>>>>>3,1
//>>>>>>>>>>>>>>>>>>>>>>>>3,2

using namespace std;

struct _data
{
    
};

typedef struct _data data;

class Template {
    
    
public:
    
    bool finished = false;
    
    bool is_a_solution(int a[],int k, int n)
    {
        return ( k == n );
    }
    
    void process_solution(int a[],int k , int n)
    {
    }
    
    void construct_candidates(int a[],int k, int n, int c[], int *ncandidates)
    {
        
        
        
        
        *ncandidates = 3;
    }
    
    void backtrack(int a[],int k , int  n)
    {
        int c[3];
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
                printLevel(k,i);
                backtrack(a,k,n);
                if ( finished )
                    return;
            }
        }
    }
    
    void loopIt(int n )
    {
        int a[5];  /* solution vector */
        backtrack(a,0,n);
    }
    
    void printLevel(int k,int i )
    {
        for ( int i = 0 ; i < k ; i++ )
        {
            cout << ">>>>>>>>";
        }
        cout << k << "," << i  << endl;
    }
    
};

//int main()
//{
//    Template t;
//    t.loopIt(3);
//    return 0;
//}