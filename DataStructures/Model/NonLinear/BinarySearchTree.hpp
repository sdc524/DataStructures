//
//  BinarySearchTree.hpp
//  DataStructures
//
//  Created by Cassat, Stephen on 4/12/19.
//  Copyright © 2019 Cassat Stephen. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp


#include "Tree.hpp"
#include <iostream>

using namespace std;

template <class Type>
classBinarySearchTree : public Tree<Type>

protected:

int calculateSize(BinaryTreeNode<Type> * startNode);
int calculateSize(BinaryTreeNode<Type> * startNode);
bool isBalanced(BinaryTreeNode<Type> * startNode);
bool isComplete(BinaryTreeNode<Type> * startNode, int index, int size);

void inOrderTraversal(BinaryTreeNode<Type> * inStart);
void preOrderTraversal(BinaryTreeNode<Type> * preStart);
void postOrderTraversal(BinaryTreeNode<Type> * postStart);

void destroyTree(BinaryTreeNode<Type> * node);

BinaryTreeNode<Type> * getRightMostChild(BinaryTreeNode<Type> * current);
BinaryTreeNode<Type> * getLeftMostChild(BinaryTreeNode<Type> * current);

void removeNode(BinaryTreeNode<Type> * removeMe);

public:
BinarySearchTree();
~BinarySearchTree();

BinaryTreeNode<Type> * getRoot();

void inOrderTraversal();
void preOrderTraversal();
void postOrderTraversal();
void demoTraversalSteps(BinaryTreeNode<Type> * node);

int getSize();
int getHeight();
bool isComplete();
bool isBalanced();

bool contains(Type value);
void insert(Type itemToInsert);
void remove(Type value);

Type findMinimum();
Type findMaximum();

#endif /* BinarySearchTree_h */
