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
#include <queue>
#include <map>

using namespace std;

struct Node {
	int value;
    int index;
	Node *rightChild;
	Node *leftChild;
};
typedef struct Node Node;

class BinarySearchTree {
	Node *root;
    
public:
	BinarySearchTree();
	void constructTree(Node *top, int value);
	Node *getRoot();
	void setRoot(int val);
	void inorderTraversal(Node *root);
	void preorderTraversal(Node *root);
	void postorderTraversal(Node *root);
    int LeastCommonAncestor(Node *root);
	int size(Node *root);
	int maximumDepth(Node *root);
	void constructTreeFromInorderAndPreOrder(int inorder[], int preorder[], int nodes);
	bool isSubTree(Node *tree);
    void findVerticalSum();

	~BinarySearchTree();
};


class BST : TutorialBase {
public:
	bool compareTrees(Node *roota, Node *rootb);
    int  hasPathSum(Node *tree, int sum);
    void printLevelByLevel(Node *root);
    int depth(Node *root);
    void allInOneTraversal(Node *root);
    void iterativePostOrder(Node *root);
	void serializeBinaryTree(Node *root,queue<Node *>q);
    int diameter(Node *root);
    bool isSymmetric(Node *leftSubTree,Node *rightSubTree);
    void printVertical(Node *root,int index,map<int,vector<int>>& list) ;
    int isBalancedTree(Node *root);
    int maxDepth(Node *root);
    int minDepth(Node *root);

    virtual void Run();
};
#endif /* defined(__AlgorithmTutorials__BST__) */
