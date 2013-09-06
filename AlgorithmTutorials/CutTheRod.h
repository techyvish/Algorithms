//
//  CutTheRod.h
//  AlgorithmTutorials
//
//  Created by Vishal on 25/07/13.
//  Copyright (c) 2013 Vishal. All rights reserved.
//

#ifndef __AlgorithmTutorials__CutTheRod__
#define __AlgorithmTutorials__CutTheRod__

#include <iostream>
#include "TutorialBase.h"

class CutTheRod : public TutorialBase
{
    int S[8] = {1,2,3,4,5,6,7,8};
    int V[8] = {1,5,8,9,10,17,17,20};
    int B[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
public:
    int cutTheRod(int s, int e);
    virtual void run();
};

#endif /* defined(__AlgorithmTutorials__CutTheRod__) */
