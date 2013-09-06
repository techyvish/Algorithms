//
//  CoinChange.h
//  AlgorithmTutorials
//
//  Created by Vishal on 19/07/13.
//  Copyright (c) 2013 Vishal. All rights reserved.
//

#ifndef __AlgorithmTutorials__CoinChange__
#define __AlgorithmTutorials__CoinChange__

#include <iostream>
#include "TutorialBase.h"

class CoinChange : public TutorialBase {
    int *results;
public:
    
    int numberOfCoinsRequired(int sum, int coins[]);
    int change ( int sum , int coins[] );
    void call(int sum, int coins[] );
    virtual void run();
};

#endif /* defined(__AlgorithmTutorials__CoinChange__) */
