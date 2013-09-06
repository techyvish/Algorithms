//
//  GraphColoring.h
//  AlgorithmTutorials
//
//  Created by Vishal on 7/07/13.
//  Copyright (c) 2013 Vishal. All rights reserved.
//

#ifndef __AlgorithmTutorials__GraphColoring__
#define __AlgorithmTutorials__GraphColoring__

#include <iostream>
#include "TutorialBase.h"

class GraphColoring : public TutorialBase{

    int G[5][5] = { {0, 0, 0, 0, 0,},
                    {0, 1, 1, 0, 1 },
                    {0, 1, 1, 1, 1 },
                    {0, 0, 1, 1, 1 },
                    {0, 1, 1, 1, 1 } };
    int x[5] = {0};
    int m;
public:
    
    GraphColoring();
    void cerateAdjecencyMatrix();
    void colorGraph(int k, int n);
    int getNodeColor(int k);
    void printNodeColors();

    virtual void run();
};

#endif /* defined(__AlgorithmTutorials__GraphColoring__) */
