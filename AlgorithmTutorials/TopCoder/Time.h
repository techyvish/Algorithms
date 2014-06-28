//
//  Time.h
//  AlgorithmTutorials
//
//  Created by Vishal Patel on 6/28/14.
//  Copyright (c) 2014 Vishal. All rights reserved.
//

#ifndef __AlgorithmTutorials__Time__
#define __AlgorithmTutorials__Time__

#include <iostream>
#include "TutorialBase.h"
#include <iostream>
#include <fstream>
#include <sstream>


class Time : public TutorialBase {
    
public:
    
    std::string whatTime(int seconds)
    {
        std::stringstream result;
        if ( !seconds ){
            result << 0 << ":" << 0 << ":" << 0;
            return result.str();
        }
        int secs = seconds % 60 ;
        int reminder = seconds / 60;
        int mins = reminder % 60 ;
        int hours = reminder / 60;
        result << hours << ":" << mins << ":" << secs;
        return result.str();
    }
    
    virtual void run()
    {
        whatTime(3661);
    }
};

#endif /* defined(__AlgorithmTutorials__Time__) */


