//
//  PelindromicSubSeq.h
//  AlgorithmTutorials
//
//  Created by Vishal on 5/08/13.
//  Copyright (c) 2013 Vishal. All rights reserved.
//

#ifndef __AlgorithmTutorials__PelindromicSubSeq__
#define __AlgorithmTutorials__PelindromicSubSeq__

#include <iostream>
#include "TutorialBase.h"

class LongestPelindromicSubsequence: public TutorialBase {
    
    
public:
    LongestPelindromicSubsequence();
    int LPS(char X[],int from,int to);
    virtual void run();
};

#endif /* defined(__AlgorithmTutorials__PelindromicSubSeq__) */
