//
//  FlipColor.cpp
//  AlgorithmTutorials
//
//  Created by Vishal Patel on 21/08/2014.
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
#include <list>
#include <string>
#include <map>
#include <set>

using namespace std;

#define NMAX 50

typedef vector<int> VI ; typedef vector<vector<int>> VVI;
typedef vector<string> VS; typedef vector<vector<string>> VVS;
typedef signed long long i64; typedef unsigned long long u64;

#define MAX 8
class FlipColor
{
    public:
    
    void flipColor(int a[][MAX],int x, int y)
    {
        if ( x < 0 || y < 0 )
            return;
        if ( x >= MAX || y >= MAX )
            return;
        
        if ( a[x][y] != 1 )
            a[x][y] = 1;
        else
            return;
        
        if ( a[x+1][y] != 1 )
            flipColor(a, x+1, y);
        
        if ( a[x][y+1] != 1 )
            flipColor(a, x  , y+1);
        
        if ( a[x-1][y] != 1 )
            flipColor(a, x-1, y);
        
        if ( a[x][y-1] != 1 )
            flipColor(a, x  , y-1);
    }
    
};

int  main()
{
    FlipColor fp;
    int arr[MAX][MAX]= {
        {1,1,0,0,0,0,1,1},
        {1,1,0,0,0,0,1,1},
        {1,1,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {1,1,0,0,0,0,1,1},
        {1,1,0,0,0,0,1,1},
    };
    
    fp.flipColor(arr, 4, 4);
    
    for ( int i = 0 ; i < MAX ; i++)
    {
        for ( int j= 0 ; j < MAX ; j++)
        {
            cout << arr [i][j] << " ";
        }
        cout << "\n";
    }
}

