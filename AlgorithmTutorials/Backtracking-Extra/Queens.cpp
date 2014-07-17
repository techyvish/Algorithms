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

/**
 *  Place N Queens on chess board so that they can not threat each other
 *  horizontally or vertically or diagonally.
 *
 *   O  X  O  O
 *   O  O  O  X
 *   X  O  O  O
 *   O  O  X  O
 *
 *  This program uses generalised backtrack solution from template.
 *  This program is to prove that backtrack general solution works.
 *
 *  Concept: we'll carefully bruteforce to findout all posible position
 *  we can place queen on a chess board. we'll then if one perticular
 *  solution doesn't work then we'll backtrack and fix the problem.
 *
 **/

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
        return ( k == n - 1);
    }
    
    void process_solution(int a[][NMAX],int k , int n,int *x)
    {
        for ( int i = 0 ; i < n ; i ++ )
        {
            for ( int j = 0 ; j < n ; j ++ )
            {
                if ( x[i] == j )
                {
                    cout << " X ";
                }
                else
                {
                    cout << " O ";
                }
            }
            cout << endl;
        }
        cout << endl;
        finished = true;
    }
    
    void construct_candidates(int a[][NMAX],int k, int n, int c[], int *ncandidates,int x[])
    {
        cout << endl;
        for ( int col = 0 ; col < n ; col ++) // for each column
        {
            bool leagal_move = true;
            for ( int row = 0 ; row < k ; row++ ) // we'll examine each row to find out wether queen can be placed or not.
            {
                if ( x[row] == col )   // is it in same column ??
                    leagal_move = false;
                if ( abs(col - x[row] ) == abs( k - row ) )  // check difference of columns and rows is equal for diagonal threat.
                    leagal_move = false;
            }
            if ( leagal_move == true )
            {
                c[*ncandidates] = col;  // if we can place queen then add remaining positions where queens can be paced
                                        // for future use.
                *ncandidates = *ncandidates + 1;
            }
        }
    }
    
    void backtrack(int a[][NMAX],int k , int  n,int *x)
    {
        int *c = new int[NMAX]; //final solution vector
        std::fill_n(c, NMAX, 0);
        
        int ncandidates = 0;
        int i = 0;
        
        if ( is_a_solution(a,k,n))
            process_solution(a,k,n,x);
        else
        {
            k = k+1; // rows
            construct_candidates(a,k,n,c,&ncandidates,x);
            for (  i =0 ; i < ncandidates ; i++ )      //TODO: find out where i > ncadidates that mean we've to remove item
            {                                          // from last column and back track
                a[k][i] = c[i];
                x[k] = c[i];  // store queen position in final solution vector.
                //cout << "Can we place queen at row " << k << "  and column " << c[i] << "?" << endl;
                backtrack(a,k,n,x);
                if ( finished )
                    return;
            }
            
            delete c; // clean up
        }
    }
    
    void planceQueens(int n )
    {
        int a[NMAX][NMAX] = {0};  /* solution vector */
        int *x = new int[NMAX];
        std::fill_n(x, NMAX, INT_MAX);
        backtrack(a,-1,n,x);
        delete x; // clean up;
    }
    
};

//int main()
//{
//    Queens q;
//    q.planceQueens(4);
//    return 0;
//}