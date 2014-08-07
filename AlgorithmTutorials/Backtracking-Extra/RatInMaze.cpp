//
// Created by Vishal Patel on 6/08/2014.
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

#define  COLUMN 5

using namespace std;

typedef pair<int,int> MyPair;

struct _data
{

};

typedef struct _data data;

class RateInMaze {

public:

    bool finished = false;

    bool is_a_solution(int a[][COLUMN],int k, int n)
    {
        return ( k == n );
    }

    void process_solution(int a[][COLUMN],int k , int n)
    {

    }

    void construct_candidates(int a[][COLUMN],int k, int n,vector<MyPair>& c, int *ncandidates,int column)
    {
        // TODO: add vector to for next position to traverse.
        int p = 0;
        if ( a[k+1][column] != 0  ) {
            MyPair r(k+1,column);
            c.push_back(r);
            *ncandidates = *ncandidates + 1;
        }

        if ( a[k][column+1] != 0 )
        {
            MyPair r(k,column+1);
            c.push_back(r);
            *ncandidates = *ncandidates + 1;
        }
    }

    void backtrack(int a[][COLUMN],int k , int  n,int column)
    {
        vector<MyPair> c;
        int ncandidates;
        int i ;

        if ( is_a_solution(a,k,n))
            process_solution(a,k,n);
        else
        {
            k = k+1;
            construct_candidates(a,k,n,c,&ncandidates,column);
            for ( i = 0 ; i < ncandidates ; i++ )
            {
                MyPair p = c[i];
                k = p.first;
                backtrack(a,k,n,p.second);
                if ( finished )
                    return;
            }
        }
    }

    void showPath(int n)
    {
        int a[5][5] = {{1, 0, 0, 0},
                       {1, 1, 0, 1},
                       {0, 1, 0, 0},
                       {1, 1, 1, 1}};

        backtrack(a,-1,n,0);
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

int main()
{
    RateInMaze rate;
    rate.showPath(4); // 4x4 grid
    return 0;
}
