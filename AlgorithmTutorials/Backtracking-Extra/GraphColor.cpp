//
// Created by Vishal Patel on 7/08/2014.
// Copyright (c) 2014 Vishal. All rights reserved.
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

#define COLUMN 5
#define ROW    5

using namespace std;

struct _data
{

};

typedef struct _data data;

class GraphColor {


public:

    bool finished = false;

    bool is_a_solution(int a[][COLUMN],int k, int n)
    {
        return ( k == n );
    }

    void process_solution(int a[][COLUMN],int k , int n)
    {
    }

    void construct_candidates(int a[][COLUMN],int k, int n, int c[], int *ncandidates)
    {

        *ncandidates = 3;
    }

    void backtrack(int a[][COLUMN],int k , int  n,int colors)
    {
        int c[3];
        int ncandidates = 0;

        if ( is_a_solution(a,k,n))
            process_solution(a,k,n);
        else
        {
            k = k+1;
            construct_candidates(a,k,n,c,&ncandidates);
            for (int i = 0 ; i < ncandidates ; i++ )
            {
                //a[k] = c[i];
                backtrack(a,k,n,colors);
                if ( finished )
                    return;
            }
        }
    }

    void colorIt(int n)
    {
        /* Create following graph and test whether it is 3 colorable
         (3)---(2)
          |   / |
          |  /  |
          | /   |
         (0)---(1)
        */
        int a[ROW][COLUMN] = {{0, 1, 1, 1},
                               {1, 0, 1, 0},
                               {1, 1, 0, 1},
                               {1, 0, 1, 0},
        };
        int colors = 3;
        backtrack(a,0,n,colors);
    }
};

int main()
{
    GraphColor g;
    g.colorIt(3);
    return 0;
}
