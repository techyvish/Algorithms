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

    bool is_a_solution(int a[][COLUMN],int k, int n,int column)
    {
        return (k == n-1 && column == n-1);
    }

    void process_solution(int a[][COLUMN],int k , int n, vector<MyPair>& path)
    {
        cout << "0,0";
        for ( int i = 0 ; i < path.size(); i++ )
        {
            MyPair p = path[i];
            cout << " --> " << p.first << "," << p.second ;
        }
        cout << endl;
        finished = true;
    }

    void construct_candidates(int a[][COLUMN],int k, int n,vector<MyPair>& c, int *ncandidates,int column)
    {
        // TODO: add vector to for next position to traverse.
        int p = 0;
        if ( k < n && a[k+1][column] != 0  ) {
            MyPair r(k+1,column);
            c.push_back(r);
            *ncandidates = *ncandidates + 1;
        }

        if ( column < n && a[k][column+1] != 0 )
        {
            MyPair r(k,column+1);
            c.push_back(r);
            *ncandidates = *ncandidates + 1;
        }
    }

    void backtrack(int a[][COLUMN],int k , int  n,int column, vector<MyPair>& path)
    {
        vector<MyPair> c;
        int ncandidates = 0 ;
        int i ;

        if ( is_a_solution(a,k,n,column))
            process_solution(a,k,n,path);
        else
        {
            //k = k+1;
            construct_candidates(a,k,n,c,&ncandidates,column);
            for ( int i = 0 ; i < ncandidates ; i++ )
            {
                MyPair p = c[i];
                k = p.first;
                path.push_back(p);
                backtrack(a,k,n,p.second,path);
                path.pop_back();
                if ( finished )
                    return;
            }
        }
    }

    void showPath(int n)
    {
        int a[5][5] = {{1, 1, 1, 0},
                       {1, 1, 1, 1},
                       {0, 0, 0, 1},
                       {1, 1, 1, 1}};

        vector<MyPair> path;

        backtrack(a,0,n,0,path);

        if ( !finished )
        {
            cout << "Rat can't get out from the maze :( " << endl;
        }
    }

};

//int main()
//{
//    RateInMaze rate;
//    rate.showPath(4); // 4x4 grid
//    return 0;
//}
