//
//  Parentheses.h
//  AlgorithmTutorials
//
//  Created by Vishal on 9/07/13.
//  Copyright (c) 2013 Vishal. All rights reserved.
//

#ifndef __AlgorithmTutorials__Parentheses__
#define __AlgorithmTutorials__Parentheses__

#include <iostream>
#include "TutorialBase.h"
using namespace std;
class Parentheses : public TutorialBase {
    
    
public:
    
    void printParenthesis(int leftperenthesis, int rightparanthesis,string str);
    virtual void run();
    
};

#endif /* defined(__AlgorithmTutorials__Parentheses__) */
