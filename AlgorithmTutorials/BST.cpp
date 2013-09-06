//
//  BST.cpp
//  AlgorithmTutorials
//
//  Created by Vishal on 27/06/13.
//  Copyright (c) 2013 Vishal. All rights reserved.
//

#include "BST.h"
using namespace std;
BinarySearchTree::BinarySearchTree() {
	root = new Node;
	root->leftChild = NULL;
	root->rightChild = NULL;
}

void BinarySearchTree::constructTree(Node *root, int value) {
	if (root != NULL) {
		Node *node = new Node();
		node->value = value;
        
		if (value < root->value) {
			if (root->leftChild == NULL) {
				root->leftChild = node;
			}
			else {
				constructTree(root->leftChild, value);
			}
		}
        
		if (value > root->value) {
			if (root->rightChild == NULL) {
				root->rightChild = node;
			}
			else {
				constructTree(root->rightChild, value);
			}
		}
	}
	else {
		Node *node = new Node();
		node->value = value;
		node->leftChild = NULL;
		node->rightChild = NULL;
	}
}

Node *BinarySearchTree::getRoot() {
	if (root != NULL)
		return root;
	return NULL;
}

void BinarySearchTree::setRoot(int val) {
	root->value = val;
}

void BinarySearchTree::inorderTraversal(Node *root) {
	if (root != NULL) {
		inorderTraversal(root->leftChild);
		cout << root->value << ",";
		inorderTraversal(root->rightChild);
	}
}

void BinarySearchTree::preorderTraversal(Node *root) {
	if (root != NULL) {
		cout << root->value << ",";
		preorderTraversal(root->leftChild);
		preorderTraversal(root->rightChild);
	}
}

void BinarySearchTree::postorderTraversal(Node *root) {
	if (root != NULL) {
		postorderTraversal(root->leftChild);
		postorderTraversal(root->rightChild);
		cout << root->value << ",";
	}
}

int BinarySearchTree::LeastCommonAncestor(Node *root) {
	// Do inorder traversal
	// Do post order traversal
	// Find elements between two node from inorder traversal
	// Rank them from post order traversal
	// element with highest rank is the root
	return 0;
}

BinarySearchTree::~BinarySearchTree() {
	//delete tree;
}

int BinarySearchTree::size(Node *root) {
	if (root != NULL)
		return (size(root->leftChild) + 1 + size(root->rightChild));
	else
		return 0;
}

void BST::Run() {
	int nodeVals[10] = { 30, 10, 5, 15, 20, 40, 35, 50 };
    
	BinarySearchTree *bst = new BinarySearchTree();
	bst->setRoot(nodeVals[0]);
	for (int i = 1; i < 8; i++) {
		bst->constructTree(bst->getRoot(), nodeVals[i]);
	}
    
	bst->inorderTraversal(bst->getRoot());
	cout << endl;
	bst->preorderTraversal(bst->getRoot());
	cout << endl;
	bst->postorderTraversal(bst->getRoot());
	cout << endl;
    
    cout << "size of tree : " << bst->size(bst->getRoot());
    
	delete bst;
}
