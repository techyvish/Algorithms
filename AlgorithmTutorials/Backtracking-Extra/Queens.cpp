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

#define NMAX 10

using namespace std;

struct _data
{
    
};

typedef struct _data data;

class Queens {
    
    
public:
    
    bool finished = false;
    
    bool is_a_solution(int a[][NMAX],int k, int n)
    {
        return ( k == n );
    }
    
    void process_solution(int a[][NMAX],int k , int n)
    {
    }
    
    void construct_candidates(int a[][NMAX],int k, int n, int c[], int *ncandidates)
    {
        for (int i = 0 ; i < n ; i++ )
        {
            if ( canQueenBePlaced(a,k,i,n) )
            {
                //Erase old position (if any) and place the queen at new position.
                
                
                
                //and count remaining candidates for future.
                *ncandidates = *ncandidates + 1;
            }
            else
            {
                *ncandidates = 0 ; // no candidates left to try -> backtrack.
            }
        }
    }
    
    void backtrack(int a[][NMAX],int k , int  n)
    {
        int c[3];
        int ncandidates;
        int i ;
        
        if ( is_a_solution(a,k,n))
            process_solution(a,k,n);
        else
        {
            k = k+1; // rows
            construct_candidates(a,k,n,c,&ncandidates);
            for ( i = 0 ; i < ncandidates ; i++ )
            {
                a[k][i] = c[i];
                backtrack(a,k,n);
                if ( finished )
                    return;
            }
        }
    }
    
    void planceQueens(int n )
    {
        int a[NMAX][NMAX];  /* solution vector */
        backtrack(a,0,n);
    }
    
    bool canQueenBePlaced(int a[][NMAX],int row, int col,int n)
    {
        for (int i = 0 ; i < row ; i++ )
        {
            for ( int j = 0 ; j < col ; j++ )
            {
                if ( a[i][j] == 1 )
                {
                    if ( row == i || col == j)
                        return false;
                }
                
                if ( a[abs(i - row)][abs(j-col)] == 1 )
                {
                    return false;
                }
            }
        }
        return true;
    }
    
};

int main()
{
    Queens q;
    q.planceQueens(8);
    return 0;
}