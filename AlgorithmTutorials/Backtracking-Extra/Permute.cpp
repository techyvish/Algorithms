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

/**** 
*  we can define out think of our methodology here as 
                    Fix position and 
                    swap position as described in following diagaram.

                                        {a,b,c}
                                           |
                    ________________________________________________
                    |                      |                        |
                {a,b,c}                 {b,a,c}                 {c,b,a}            // here we fix first position and swap all characters on that position.
                   |                       |                        |
            __________              ______________             ______________
            |         |             |             |            |             |
        {a,b,c}    {a,c,b}        {b,a,c}    {b,c,a}         {c,b,a}      {c,a,b}  // here we fix second position and swap remaning characters on that
                                                                                   // position.

*/

#define NMAX 5

struct _data
{
    
};

typedef struct _data data;

class Permute {
    
public:
    
    bool finished = false;
    
    bool is_a_solution(int a[],int k, int n)
    {
        return ( k == n - 1);
    }
    
    void process_solution(int a[],int k , int n)
    {
        cout << "{ ";
        for ( int i = 0 ; i < n ; i++ )
            cout << (char)a[i]  << " ";
        cout << "}" << endl;
    }
    
    void construct_candidates(int a[],int k, int n, int c[], int *ncandidates)
    {
        int in_perm[NMAX] = {0};                // Fixing the participant in permutation.
        for ( int i = 0 ; i < k ; i++ )
        {
            in_perm[i] = true;
        }
        
        for ( int i = 0; i < n ; i++ )
        {
            if ( in_perm[i] == false )
            {
                c[*ncandidates] = a[i];
                *ncandidates = *ncandidates + 1;
            }
        }
        cout << endl;
    }
    
    void backtrack(int a[],int k , int  n)
    {
        int c[NMAX];
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
               // cout << "a[" << k <<"] =" << (char) a[k] << " c[" << i <<"] =" << (char) c[i] << endl;
                for ( int p = k ; p < n ;p++ ) //After locking down position we're swapping characters here.
                {
                    if (a[p] == c[i])
                    {
                        int temp = a[k];
                        a[k] = c[i];
                        a[p] = temp;
                    }
                }
                //printLevel(k,i);
                backtrack(a,k,n);
                if ( finished )
                    return;
            }
        }
    }
    
    void getAllPermutations(int a[],int n )
    {
        backtrack(a,-1,n);
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
//    Permute p;
//    int a[] = {'a','b','c'};
//    p.getAllPermutations(a,3);
//    return 0;
//}