//
//  LIS.h
//  AlgorithmTutorials
//
//  Created by Vishal on 22/07/13.
//  Copyright (c) 2013 Vishal. All rights reserved.
//

#ifndef __AlgorithmTutorials__LIS__
#define __AlgorithmTutorials__LIS__

#include "TutorialBase.h"
#include <iostream>

class MSS : public TutorialBase {
    
    int *s;
public:
    
    int  mss(int arr[], int n );
    virtual void run();
    
};

#endif /* defined(__AlgorithmTutorials__LIS__) */
