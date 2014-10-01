//
//  Rabin-Karp.c
//  AlgorithmTutorials
//
//  Created by Vishal Patel on 22/09/2014.
//  Copyright (c) 2014 Vishal. All rights reserved.
//

#include <stdio.h>
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


class RobinKarp
{
public:
    int  search(string txt ,string pat , int q)
    {
        int M = (int)pat.size();
        int N = (int)txt.size();
        int i , j = 0;
        int p = 0;
        int t = 0;
        int h = 1;
        int d = 256;
        
        for ( int i = 0 ; i < M-1 ; i++ )
        {
            h = (h*d) % q;
        }
        
        
        // Calculate the hash value of pattern and first window of text
        for (i = 0; i < M; i++)
        {
            p = (d*p + pat[i])%q;
            t = (d*t + txt[i])%q;
        }
        
        
        // Slide the pattern over text one by one
        for (i = 0; i <= N - M; i++)
        {
            
            // Chaeck the hash values of current window of text and pattern
            // If the hash values match then only check for characters on by one
            if ( p == t )
            {
                /* Check for characters one by one */
                for (j = 0; j < M; j++)
                {
                    if (txt[i+j] != pat[j])
                        break;
                }
                if (j == M)  // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
                {
                    printf("Pattern found at index %d \n", i);
                }
            }
            
            // Calulate hash value for next window of text: Remove leading digit,
            // add trailing digit
            if ( i < N-M )
            {
                t = (d*(t - txt[i]*h) + txt[i+M])%q;
                
                // We might get negative value of t, converting it to positive
                if(t < 0) 
                    t = (t + q); 
            }
        }
        return 0;
    }
};

//int main()
//{
//
//    RobinKarp r ;
//    r.search("test for tests","test",101);
//    return 0;
//}