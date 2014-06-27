//
//  DerivativeSequence.h
//  AlgorithmTutorials
//
//  Created by Vishal Patel on 27/06/2014.
//  Copyright (c) 2014 Vishal. All rights reserved.
//

#ifndef __AlgorithmTutorials__DerivativeSequence__
#define __AlgorithmTutorials__DerivativeSequence__

#include <iostream>
#include "TutorialBase.h"
#include "prettyprint.hpp"

class DerivativeSequence : public TutorialBase {
    
public:
    
    DerivativeSequence();
    ~DerivativeSequence();
    virtual void run();
    void generateSequence(int *a, int length, int order);
    bool allZero(int *arr,int length);
};

#endif /* defined(__AlgorithmTutorials__DerivativeSequence__) */
