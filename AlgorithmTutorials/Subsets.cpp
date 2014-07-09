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

using namespace std;

struct _data
{
    
};

typedef struct _data data;

class Subsets {
    
    
public:
    
    bool finished = false;
    
    bool is_a_solution(int a[],int k, int n)
    {
        return ( k == n );
    }
    
    void process_solution(int a[],int k , int n)
    {
        int i;
        cout << "{";
        for (i=1; i<=k; i++)
            if (a[i] == true) printf(" %d",i);
        cout << " }\n" << endl;
    }

    void construct_candidates(int a[],int k, int n, int c[], int *ncandidates)
    {
        c[0] = true;
        c[1] = false;
        *ncandidates = 2;
    }
    
    void backtrack(int a[],int k , int  n)
    {
        
        int c[2];
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
    
    void generateAllSubsets(int n )
    {
        int a[2];  /* solution vector */
        backtrack(a,0,n);
    }
    
};


int main()
{

    Subsets s;
    s.generateAllSubsets(3);
    return 0;
}