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

#define NMAX 3

class PermuteNumbers {
    
public:
    
    bool finished = false;
    
    bool is_a_solution(int a[],int k, int n)
    {
        return ( k == n);
    }
    
    void process_solution(int a[],int k , int n)
    {
        int i;
        cout << "{";
        for (i=1; i <= k ; i++)
            printf(" %d",a[i]);
        cout << " }\n" << endl;
    }
    
    void construct_candidates(int a[], int k, int n, int c[], int *ncandidates)
    {
        cout << " { ";
        for (int i=0; i< n ; i++)
            printf(" %d",a[i]);
        cout << " }\n" << endl;
        int i;                          /* counter */
        bool in_perm[NMAX];             /* who is in the permutation? */
        for (int i=1; i<NMAX; i++) in_perm[i] = false;
        for (int i=0; i<k; i++) in_perm[ a[i] ] = true;
        *ncandidates = 0;
        for (i=1; i<=n; i++)
        {
            if (in_perm[i] == false) {
                c[ *ncandidates] = i;
                *ncandidates = *ncandidates + 1;
            }
        }
    }
    
    void backtrack(int a[],int k , int  n)
    {
        int c[NMAX] = {0,0,0};
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
                cout << ">>{";
                for (i=0; i< n ; i++)
                    printf(" %d",a[i]);
                cout << " }\n" << endl;
                backtrack(a,k,n);
                //if ( finished )
                //    return;
            }
        }
    }
    
    void generateAllPerms(int a[],int n )
    {
        backtrack(a,0,n);
    }
    
};

//int main()
//{
//    PermuteNumbers perm;
//    int a[NMAX] = {1,2,3};
//    perm.generateAllPerms(a,3);
//    return 0;
//}