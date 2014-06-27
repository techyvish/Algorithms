//
//  DerivativeSequence.cpp
//  AlgorithmTutorials
//
//  Created by Vishal Patel on 27/06/2014.
//  Copyright (c) 2014 Vishal. All rights reserved.
//

#include "DerivativeSequence.h"


DerivativeSequence::DerivativeSequence()
{
    
}

DerivativeSequence::~DerivativeSequence()
{
    
}

void DerivativeSequence::generateSequence(int a[], int length, int order)
{
     if ( order == 0 ) {
        // TODO: if zero return array
        return;
    }
    else
    {
        order --;
        int counter = 0;
        if ( allZero(a,length))
        {
            return;
        }
        int *result = new int[length];
        for ( int i = 0 ; i < length ; i++ )
        {
            if ( i < length - 1) {
                result[i] = a[i+1] - a[i];
                std::cout << result[i] <<" ";
                counter ++;
            }
            else
            {
                result[i] = '\n';
            }
        }
        std::cout << result << std::endl;
        generateSequence(result, counter, order);
    }
}

bool DerivativeSequence::allZero(int *arr,int length)
{
    bool zero = true  ;
    for ( int i = 0  ; i < length ; i++ )
    {
        zero &= ( arr[i] == 0);
        if ( !zero )
            break;
    }
    return zero;
}

void DerivativeSequence::run()
{
    DerivativeSequence d ;
    //int array[] = {5,6,3,9,-1};
    int array[] = {4,4,4,4,4,4,4,4};
    int length = 5;
    int order = 3;
    d.generateSequence(array, length , order);
}


