//
//  LIS.cpp
//  AlgorithmTutorials
//
//  Created by Vishal Patel on 7/6/14.
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

using namespace std;

class RecursiveLIS {
    
    
public:
    
    bool finished = false;
    int max = 0;
    
    bool is_a_solution(int a[],int k, int n)
    {
        return ( k == n );
    }
    
    void process_solution(int a[],int k , int n)
    {
    }
    
    void construct_candidates(int a[],int k, int n, int c[], int *ncandidates)
    {
        int tmpMax =0;
        int count = 0;
//        for ( int i = k ; i < n ; i ++ )
//        {
//            if ( a[i] > tmpMax )
//            {
//                tmpMax = a[i];
//                count ++;
//            }
//        }
        
        tmpMax = 0;
        for ( int i = 0 ; i <= k ; i++ )
        {
            if ( a[i] <= a[n-1])
            {
                if ( (a[i] >= tmpMax) && (a[i] <= a[n-1]))
                {
                    tmpMax = a[i];
                    count ++;
                }
               // include = true;
            }
        }
        if ( count > max )
            max = count;
        *ncandidates = 1;
    }
    
    void backtrack(int a[],int k , int  n)
    {
        int c[3];
        int ncandidates;
        int i ;
        
        if ( is_a_solution(a,k,n))
            process_solution(a,k,n);
        else
        {
            k = k+1;
            construct_candidates(a,k,n,c,&ncandidates);
            for ( i = 0 ; i < ncandidates ; i++ )
            {
                //a[k] = c[i];
                //k = i;
                backtrack(a,k,n);
                if ( finished )
                    return;
            }
        }
    }
    
    void loopIt(int a[],int n )
    {
        backtrack(a,0,n);
    }
    
    
};

class LIS {
    
public:
    
    int res  = 0;
    int  max_ending_here = 0;
    
    int lisLength(int arr[],int n,int *max_ref)
    {
        for(int i = 1; i < n; i++)
        {
             res = lisLength(arr, i, max_ref);
            if (arr[i-1] < arr[n-1] && res + 1 > max_ending_here)
            {
                
            }
        }
        return 0;
    }
    
    int getLongestLenght(int a[],int length)
    {
    
        vector<int> lis(length);
        vector<int> lisArr(length);
        
        lis[0] = 1;
        int k = 0;
        bool include = true;
        
        for ( int i = 1 ; i < length ; i++  )
        {
            include = false;
            int max = 0;
            for ( int j = 0 ; j < i ; j++ )
            {
                cout << a[j] << " " << a[i] << " " << "lis[ " << j << " ]" << lis[j] << endl;
                
                if ( a[j] < a[i])
                {
                    if ( lis[j] > max )
                    {
                        max = lis[j];
                        lisArr[k] = a[j];
                    }
                    include = true;
                }
            }
            
            if (include) {
                lis[i] = 1 + max;
                k++;
            }
            else
                lis[i] = 1;
            
        }
        
        sort(lis.begin(), lis.end());
        cout << lis[length -1]  << endl;
        return  lis[length -1];
    }
    
};



//int main()
//{
//    int a[] = {10,22,8,33,9,21,50,41,5,10,4,11,6,12,3,13,53,14,1,15};
//    //int a[] = { 5,3,4,8,6,7};
//    
//   //RecursiveLIS lis;
//   //lis.backtrack(a, -1, 20);
//
//    LIS t;
//    int length = t.getLongestLenght(a, 20);
//    
//   // int length = l.getLongestUsingRecursion(a,9);
//   // cout << length ;
//   
////    LIS l;
////    int max_ref=  1;
////    l.lisLength(a, 6, &max_ref);
//    return  0;
//}
