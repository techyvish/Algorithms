//
//  BST.cpp
//  AlgorithmTutorials
//
//  Created by Vishal on 27/06/13.
//  Copyright (c) 2013 Vishal. All rights reserved.
//

#include "BST.h"
#include <queue>

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

bool BinarySearchTree::isSubTree(Node *tree) {
	return false;
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

void BinarySearchTree::constructTreeFromInorderAndPreOrder(int inorder[], int preorder[], int nodes) {
	// in preorder first element is root.
	// and from in order you'll find right and left subtree.
	// recursily find root and subtree from inorder and preorder and
	// you can construct tree.
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

int BinarySearchTree::maximumDepth(Node *root) {
	if (root == NULL)
		return 0;
	else {
		int ldepth = maximumDepth(root->leftChild);
		int rdepth = maximumDepth(root->rightChild);
		if (ldepth > rdepth)
			return (ldepth + 1);
		else
			return (rdepth + 1);
	}
}

void BinarySearchTree::findVerticalSum() {
}

void BST::printVertical(Node *root,int index,vector<vector<int >> *list) {
    
    if ( root == NULL)
        return;
    
    vector<int> l = list->back();
    l.push_back(root->value);
    
    printVertical(root->leftChild,index-1,list);
    printVertical(root->rightChild,index+1,list);
    
}

void BST::printLevelByLevel(Node *root) {
	queue <Node *> q;
	q.push(root);
    
	while (!q.empty()) {
		Node *n = q.front();
		cout << n->value << " ";
		q.pop();
        
		if (n->leftChild != NULL) {
			q.push(n->leftChild);
		}
        
		if (n->rightChild != NULL) {
			q.push(n->rightChild);
		}
	}
}

int BST::depth(Node *root) {
	if (root == NULL) {
		return 0;
	}
	else {
		return 1 + max(depth(root->leftChild), depth(root->rightChild));
	}
}

bool BST::compareTrees(Node *roota, Node *rootb) {
	if (roota == NULL && rootb == NULL)
		return 1;
    
	return (roota->value == rootb->value &&
	        compareTrees(roota->leftChild, rootb->leftChild) &&
	        compareTrees(roota->rightChild, rootb->rightChild));
}

int BST::hasPathSum(Node *tree, int theSum) {
	if (theSum == 0)
		return true;
    
	if (tree == NULL)
		return 0;
    
	return  (hasPathSum(tree->leftChild, theSum - tree->value) ||
	         hasPathSum(tree->rightChild, theSum  - tree->value));
}

void BST::iterativePostOrder(Node *root) {
	//    1. Initially push the root into stack1.
	//    2. while stack1 is not empty pop one element from stack1 and push into stack2 and push its left and right child into stack1
	//        3. pop elements in stack2 will give the postorder
	//
	//
	//                A
	//              /   \
	//             B     C
	//            / \   /
	//           D   E F
	//
	//        stack1	       stack2
	//        A                empty
	//        BC                A
	//        BF                AC
	//        B                 ACF
	//        DE                ACFB
	//        D                 ACFBE
	//        empty             ACFBE
	//
	//        pop stack2 EBFCA -> postorder
}

void BST::allInOneTraversal(Node *root) {
	queue <Node *> inorderQueue;
	queue <Node *> preorderQueue;
	queue <Node *> postorderQueue;
    
	if (root != NULL) {
		preorderQueue.push(root);
		allInOneTraversal(root->leftChild);
		inorderQueue.push(root);
		allInOneTraversal(root->rightChild);
		postorderQueue.push(root);
	}
}

void BST::serializeBinaryTree(Node *root, queue <Node *> q) {
	if (root == NULL) {
		return;
	}
	q.push(root);
	serializeBinaryTree(root->leftChild, q);
	serializeBinaryTree(root->rightChild, q);
}

int BST::diameter(Node *root) {
	if (root == NULL) {
		return 0;
	}
    
	int lheight = depth(root->leftChild);
	int rheight = depth(root->rightChild);
    
	int ldiameter = diameter(root->leftChild);
	int rdiameter = diameter(root->rightChild);
    
	return (max((lheight + rheight +1) , max(ldiameter , rdiameter)));
}

// is mirror
bool BST::isSymmetric(Node *leftSubTree,Node *rightSubTree){

    if ( leftSubTree == NULL && rightSubTree == NULL )
        return true;
    
    if ( (leftSubTree == NULL && rightSubTree != NULL) || (leftSubTree != NULL && rightSubTree == NULL))
        return false;
    
    return ( isSymmetric(leftSubTree->leftChild, rightSubTree->rightChild) &&
             isSymmetric(leftSubTree->rightChild, rightSubTree->leftChild));
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
    
	cout << "size of tree : " << bst->size(bst->getRoot()) << endl;
	cout << "max depth    : " << bst->maximumDepth(bst->getRoot()) << endl;
    
	int tree1[10] = { 20, 10, 30 };
	BinarySearchTree *bst1 = new BinarySearchTree();
	bst1->setRoot(tree1[0]);
	for (int i = 1; i < 3; i++) {
		bst1->constructTree(bst1->getRoot(), tree1[i]);
	}
    
	int tree2[10] = { 20, 10, 30 };
	BinarySearchTree *bst2 = new BinarySearchTree();
	bst2->setRoot(tree2[0]);
	for (int i = 1; i < 3; i++) {
		bst2->constructTree(bst2->getRoot(), tree2[i]);
	}
    
	cout << "tree 1 and 2 are ";
	if (compareTrees(bst1->getRoot(), bst2->getRoot()))
		cout << "same" << endl;
	else
		cout << "not same" << endl;
	int p = hasPathSum(bst2->getRoot(), 30);
    
	printLevelByLevel(bst->getRoot()); cout << endl;
	cout << "depth of the tree is :" << depth(bst->getRoot());
    
	queue <Node *> q;
	serializeBinaryTree(bst->getRoot(), q);
    
    cout << "Diameter of the tree is : " << diameter(bst->getRoot()) << endl;
    cout << "this tree is symmetric : " << isSymmetric(bst->getRoot()->leftChild, bst->getRoot()->rightChild) << endl;
    
    vector<vector<int>> *list = new vector<vector<int>>() ;
    for ( int i = -5 ; i < 5 ;i++ ){
        vector<int> v;
        list->push_back(v);
    }
    printVertical(bst->getRoot(), 0, list);
    
//    for ( int i = 0 ; i < list.size() ;i++){
//        vector<int> v = list[i];
//        for ( int j = 0 ; j < v.size() ;j++){
//            cout << v[j];
//        }
//    }
    
	delete bst;
}
