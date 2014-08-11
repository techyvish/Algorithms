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
    int color[ROW] = {-1,-1,-1,-1,-1};
    int maxColor = 3;

    bool is_a_solution(int a[][COLUMN],int k, int n,int node)
    {
        return ( node == n - 1 );
    }

    void process_solution(int a[][COLUMN],int k , int n,int node)
    {
        finished = true;
        cout << color[0] ;
        for ( int i = 1 ; i < n ; i++ )
        {
            cout << " ," << color[i] ;
        }
        cout << endl;
    }

    void construct_candidates(int a[][COLUMN],int k, int n, int c[], int *ncandidates,int node)
    {
       int availColor = 1;
       //k = node;
       int d = 0;
       if ( color[node] == -1 )
       {
           color[node] =  availColor ++; // lets color first node.
       }
       for ( int i = 0 ; i < n; i++ )
       {
           if ( i != node ) { // lets not look at current node.
               if (a[node][i] != 0 ) { // it should be connected node.
                   if ( availColor <= maxColor) { // yes we have colors, we can color these nodes.
                       if (  (color[i] != -1) && (color[node] != color[i]) ) {  //connected node has color and current node color is not equal to connected
                                                                             //node color.
                           // then Do nothing.
                       }
                       else if (color[i] == -1) { // connected node is not colored.
                           color[i] = availColor;
                           c[d++] = i;
                           *ncandidates = *ncandidates + 1;
                       }
                       else if (color[node] == color[i]) { // connected node has same color as current node.
                           availColor = color[i];
                           if ( availColor < maxColor) { // if colors available then update the color
                               color[i] = ++availColor;
                           }
                           else // can't color this node at the moment, we'll get back to this.
                           {
                               color[i] = -1;
                               c[i] = i;
                               *ncandidates = *ncandidates + 1;
                           }
                       }
                   }
                   else { // can't color these nodes, we'll get back to this.
                       c[i] = i;
                       *ncandidates = *ncandidates + 1;
                   }
               }
           }
       }
    }

    void backtrack(int a[][COLUMN],int k , int  n,int colors,int node)
    {
        int c[ROW] = {0};
        int ncandidates = 0;

        if ( is_a_solution(a,k,n,node))
            process_solution(a,k,n,node);
        else
        {
            k = k+1;
            construct_candidates(a,k,n,c,&ncandidates,node);
            for (int i = 0 ; i < ncandidates ; i++ )
            {
                //a[k] = c[i];
                backtrack(a,k,n,colors,c[i]);
                if ( finished )
                    return;
            }
        }
    }

    void colorIt(int n)
    {
        // Algo: color first node, pick next color and color all adjacent
        // pick next check adjacent one by one and color if same color, pick next color
        // if not colorable leave it we'll get back to it later.
        // pick next node and repeat from step 1.

        /* Create following graph and test whether it is 3 colorable
                             (3)---(2)
                              |   / |
                              |  /  |
                              | /   |
                             (0)---(1)
        */
        int a[ROW][COLUMN] =  {{0, 1, 1, 1},
                               {1, 0, 1, 0},
                               {1, 1, 0, 1},
                               {1, 0, 1, 0},
        };
        int colors = 3;
        backtrack(a,-1,n,colors,0);

        if ( !finished )
        {
            cout << "Can't color this graph using " << colors << " colors";
        }
    }
};

//int main()
//{
//    GraphColor g;
//    g.colorIt(4);
//    return 0;
//}
