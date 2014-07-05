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

class LIS {
    
public:

    int getLongestLenght(int a[],int length)
    {
        int *lis = new int[length];
        int *lisArr = new int[length];
        
        lis[0] = 1;
        int k = 0;
        bool include = true;
        
        for ( int i = 1 ; i < length ; i++  )
        {
            include = false;
            int max = 0;
            for ( int j = 0 ; j < i ; j++ )
            {
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
        
        cout << lis[length -1]  << endl;
        return 0;
    }
    
    int max(int a, int b)
    {
        return  (a > b ) ? a : b;
    }
};



int main()
{
    int a[] = {10,22,9,33,21,50,41,60,80};
 //   int a[] = { 5,3,4,8,6,7};
    
    LIS l;

    int length = l.getLongestLenght(a,9);
    cout << length ;
    return  0;
}
