//
//  NQueens.h
//  AlgorithmTutorials
//
//  Created by Vishal on 4/07/13.
//  Copyright (c) 2013 Vishal. All rights reserved.
//

#ifndef __AlgorithmTutorials__NQueens__
#define __AlgorithmTutorials__NQueens__

#include "TutorialBase.h"

#include <iostream>

class NQueens : public TutorialBase {
    int x[5] = {0,0,0,0,0};
    int n;
    
public:
    
    bool place(int k, int i);
    void nqueens(int k, int n);
    void printQueenLocations(int *x,int n);
    virtual void run();
    
};
#endif /* defined(__AlgorithmTutorials__NQueens__) */
