//
//  Queens.cpp
//  AlgorithmTutorials
//
//  Created by Vishal Patel on 10/07/2014.
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

#define NMAX 8

class Queen {
    
public:
    
    
    bool is_a_solution(int a[][NMAX], int k , int n)
    {
        return (k == n);
    }
    
    void process_solution(int a[][NMAX], int k , int n)
    {
        
    }
    
    bool queenCanBePlaced(int a[][NMAX],int k,int column,int n)
    {
        for ( int i =0 ; i < n ; i++ )
        {
            for ( int j = 0 ; j < n ; j ++ )
            {
                if ( column == j ) return false;
                if ( k == i ) return false;
                if ( abs(j-column) == abs(i - k)) return false;
                return true;
            }
            
        }
        return true;
    }
    
    bool construct_candidates(int a[][NMAX], int k, int n, int c[], int *ncandidates,int  *column)
    {
        for ( int cols = *column ; cols < n ; cols++ )
        {
            if ( queenCanBePlaced(a,k,cols,n) )
            {
                *column = cols;
                a[k][*column] = 1;
                return true;
            }
        }
        //*ncandidates = 1;
        return false;
    }
    
    void backtrack(int a[][NMAX], int k , int n)
    {
        int c[NMAX] = {0};
        int ncandidates ;
        int column = 0;
        if ( is_a_solution(a, k, n))
            process_solution(a, k, n);
        else
        {
            k = k+1;
            
            if ( construct_candidates(a, k, n, c, &ncandidates, &column ) )
            {
                backtrack(a, k, n);
            }
            else
            {
                k--;
                if ( construct_candidates(a, k, n, c, &ncandidates, &column ) )
                {
                    backtrack(a, k, n);
                }
            }
        }
    }
    
    void placeQueen(int a[][NMAX], int k ,int n)
    {
        backtrack(a, k, n);
    }
    
};

//int main()
//{
//    Queen q;
//    int a[NMAX][NMAX] = {0};
//    a[0][0] = 1;
//    q.placeQueen(a, 0, 8);
//    return 0;
//}
