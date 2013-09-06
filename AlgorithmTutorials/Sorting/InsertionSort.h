//
//  InsertionSort.h
//  AlgorithmTutorials
//
//  Created by Vishal on 30/07/13.
//  Copyright (c) 2013 Vishal. All rights reserved.
//

#ifndef __AlgorithmTutorials__InsertionSort__
#define __AlgorithmTutorials__InsertionSort__

#include <iostream>
#include "TutorialBase.h"

class InsertionSort : public TutorialBase
{
public:
    void sort(int arr[], int n);
    virtual void run();
};


#endif /* defined(__AlgorithmTutorials__InsertionSort__) */
