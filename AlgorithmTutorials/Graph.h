//
//  Graph.h
//  AlgorithmTutorials
//
//  Created by Vishal Patel on 9/09/13.
//  Copyright (c) 2013 Vishal. All rights reserved.
//

#ifndef __AlgorithmTutorials__Graph__
#define __AlgorithmTutorials__Graph__

#include <iostream>
#include "TutorialBase.h"
#include <list>

using namespace std;
class Graph : TutorialBase {
    
    int V;
    list<int> *adj;
    
public:
    
    Graph();
    Graph(int V);
    void addEdge(int v, int w);
    void DFS();
    void dfsUtil(int v, bool *visisted);
    ~Graph();
    void BFS(int s);
    
    virtual void run();
};

#endif /* defined(__AlgorithmTutorials__Graph__) */
