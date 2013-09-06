//
//  SpiralMatrix.h
//  AlgorithmTutorials
//
//  Created by Vishal on 28/06/13.
//  Copyright (c) 2013 Vishal. All rights reserved.
//

#ifndef __AlgorithmTutorials__SpiralMatrix__
#define __AlgorithmTutorials__SpiralMatrix__

#include <iostream>
#include "TutorialBase.h"

class MatrixOperations : public TutorialBase {
    
    
public:
    MatrixOperations();
    void printSpiral(int a[][5], int numCol, int numRow);
    void rotateClockWise(int a[][5],int n);
    void printMatrix(int a[][5]);
    virtual void run();
};

#endif /* defined(__AlgorithmTutorials__SpiralMatrix__) */
