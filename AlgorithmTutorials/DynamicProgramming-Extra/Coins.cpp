//
//  File.cpp
//  AlgorithmTutorials
//
//  Created by Vishal Patel on 4/07/2014.
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

class Coins {
    
    int coins[3] = {1,3,5};
    
public:
    
    Coins()
    {
        
    }
    
    int minNumberOfCoinsRequired(int sum)
    {
        int *sums = new int[sum+1];
        for ( int sumCounter = 1 ; sumCounter <= sum ; sumCounter++ )
        {
            for ( int j = 0 ; j < 3 ; j++ )
            {
                if ( (sumCounter-coins[j]) >= 0 )
                {
                        sums[sumCounter] = minimum( sums[sumCounter-1] , sums[sumCounter-coins[j]]) + 1;
                }
            }
            cout << "sum["<< sumCounter << "]" << sums[sumCounter] << endl;
        }
        return  sums[sum];
    }
    
    int minimum(int a,int b)
    {
        return (a <= b ) ? a : b;
    }
};

//int main()
//{
//    Coins c;
//    int numberOfCoins = c.minNumberOfCoinsRequired(11);
//    cout << numberOfCoins ;
//    return  0;
//}
