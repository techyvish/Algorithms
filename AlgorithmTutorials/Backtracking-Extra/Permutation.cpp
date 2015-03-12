//
//  Permutation.cpp
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

class Permutation {
    
public:

    bool thend = false;
    
    bool is_a_solution(int a[],int k,int n)
    {
        return ( k == n );
    }
    
    void process_solution(int a[],int k,int n)
    {
        for (int i = 0 ; i < k ; i++ )
        {
            cout << a[i];
        }
        cout << endl;
    }
    
    void construct_solution(int a[], int k,int n, int c[], int *ncandidates)
    {
        c[0] = 1;
        c[1] = 2;
        c[2] = 3;
        *ncandidates = 3;
    }
    
    void backtrack(int a[], int k,int n)
    {
        int c[3];
        int ncandidates = 3;
        int i ;
        if ( is_a_solution(a,k,n))
            process_solution(a,k,n);
        else
        {
            k = k + 1;
            construct_solution(a,k,n,c,&ncandidates);
            for ( i = 0 ; i < ncandidates ; i++ )
            {
                a[k] = c[i];
                backtrack(a,k,n);
                if ( thend )
                    return;
            }
        }
    }
    
    void generateAllPermutations(int a[],int n)
    {
        backtrack(a,0,n);
    }
};

//
//int main()
//{
//    Permutation p;
//    int a[] = {1,2,3};
//    p.generateAllPermutations(a,3);
//    return 0;
//}
