//
//  QuickSort.h
//  AlgorithmTutorials
//
//  Created by Vishal Patel on 11/09/13.
//  Copyright (c) 2013 Vishal. All rights reserved.
//

#ifndef __AlgorithmTutorials__QuickSort__
#define __AlgorithmTutorials__QuickSort__

#include <iostream>
#include "TutorialBase.h"

class QuickSort : public TutorialBase {
    
    
public:
    int calculatePivote(int a[],int start,int end);
    void quickSortThis(int a[],int strt ,int end);
    virtual void Run();
    void print(int a[]);

};

#endif /* defined(__AlgorithmTutorials__QuickSort__) */
