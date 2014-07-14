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

#define NMAX 50

using namespace std;

struct _data
{
    
};

typedef struct _data data;

class Parentheses {
    
    
public:
    
    bool finished = false;
    
    bool is_a_solution(int a[],int k, int n)
    {
        return ( k == (n * 2 ) - 1);
    }
    
    void process_solution(int a[],int k , int n)
    {
        if ( isValidCombo(a,n) )
        {
            for ( int i = 0 ; i < n * 2 ; i++ )
            {
                cout << (char)a[i] << " ";
            }
            cout << endl << endl;
        }
    }
    
    void construct_candidates(int a[],int k, int n, int c[], int *ncandidates)
    {
        
        for ( int i = 0 ; i < 2 ; i++ )
        {
            if ( i % 2 == 0 )
                c[*ncandidates] = ')';
            else
                c[*ncandidates] = '(';
            *ncandidates = *ncandidates + 1;
        }
    }
    
    void backtrack(int a[],int k , int  n)
    {
        int c[NMAX] = {0};
        int ncandidates = 0;
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
    
    void getAllCombinations(int n )
    {
        int a[NMAX] = {0} ;  /* solution vector */
        backtrack(a,-1,n);
    }
    
    bool isValidCombo(int a[],int n)
    {
        int countOpen = 0;
        int countClose = 0;
        
        if ( a[0] == ')' || a[n*2 - 1] == '(')
            return false;
        
        for ( int i = 0 ; i < 2 * n ; i++)
        {
            
            if ( a[i] == '(')
                countOpen ++;
            else
                countClose ++;
            
        }
        return (countOpen == countClose);
    }
    
};

//int main()
//{
//    Parentheses p;
//    p.getAllCombinations(2);
//    return 0;
//}