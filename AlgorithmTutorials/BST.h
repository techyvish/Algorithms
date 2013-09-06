//
//  BST.h
//  AlgorithmTutorials
//
//  Created by Vishal on 27/06/13.
//  Copyright (c) 2013 Vishal. All rights reserved.
//

#ifndef __AlgorithmTutorials__BST__
#define __AlgorithmTutorials__BST__

#include <iostream>
#include "TutorialBase.h"

struct Node {
    
    int value;
    Node *rightChild;
    Node *leftChild;
    
};
typedef struct Node Node;

class BinarySearchTree {
    
    Node *root;
    
public:
    
    BinarySearchTree();
    void constructTree(Node *top, int value);
    Node * getRoot();
    void setRoot(int val);
    void inorderTraversal(Node *root);
    void preorderTraversal(Node *root);
    void postorderTraversal(Node *root);
    ~BinarySearchTree();
    int LeastCommonAncestor(Node *root);
    int size(Node *root);
};


class BST : TutorialBase {
    
    
public:
    
    virtual void Run();
};
#endif /* defined(__AlgorithmTutorials__BST__) */
