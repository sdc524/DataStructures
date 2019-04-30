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
#include "../Model/Nodes/BinaryTreeNode.hpp"
#include "../Model/Structures/NonLinear/BinarySearchTree.hpp"

class BinaryTreeTester
{
private:
    BinaryTreeNode<int> testNode;
    BinarySearchTree<int> testTree;
}

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


template <class Type>
int BinarySearchTree<Type> :: getHeight()
{
    return -1;
}

template <class Type>
int BinarySearchTree<Type> :: getSize()
{
    return -1;
}

template <class Type>
bool BinarySearchTree<Type> :: isComplete()
{
    return false;
}

template <class Type>
bool BinarySearchTree<Type> :: isBalanced()
{
    return false;
}

template <class Type>
void BinarySearchTree<Type> :: inOrderTraversal()
{
    
}

template <class Type>
void BinarySearchTree<Type> :: preOrderTraversal()
{
    
}

template <class Type>
void BinarySearchTree<Type> :: postOrderTraversal()
{
    
}

template <class Type>
void BinarySearchTree<Type> :: insert(Type item)
{
}

template <class Type>
void BinarySearchTree<Type> :: contains(Type value)
{
    return false;
}

template <class Type>
void BinarySearchTree<Type> :: remove(Type item)
{
}

template <class Type>
void BinarySearchTree<Type> :: insert(Type itemToInsert)
{
    BinaryTreeNode<Type> * insertMe = new BinaryTreeNode<Type>(itemToInsert);
    BinaryTreeNode<Type> * previous = nullptr;
    BinaryTreeNode<Type> * current = this->root;
    
    if(current == nullptr)
    {
        this->root = insertMe;
    }
    else
    {
        while(current != nullptr)
        {
            prevous = current;
            if(itemToInsert < current->getData())
            {
                current = current->getLeftChild();
            }
            else if(itemToInsert > current->getData())
            {
                current = current->getRightChild();
            }
            else
            {
                cerr << "Item exists already - Exiting insert" << endl;
                delete insertMe:
                return;
            }
        }
        
        if (previous->getData() > itemToInsert)
        {
            previous->setLeftChild(insertMe);
        }
        else
        {
            previous->setRightChild(insertMe);
        }
        insertMe->setRootNode(previous;)
    }
}

template <class Type>
void BinarySearchTree<Type> :: inOrderTraversal()
{
    inOrderTraversal(this->root);
}

template <class Type>
void BinarySearchTree<Type> :: inOrderTraversal(BinaryTreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        inOrderTraversal(currentNode->getLeftChild());
        cout << currnetNode->getData() << endl;
        inOrderTraversal(currentNode->getRightChild());
    }
}

public:
void doTreeStuff();
};

void BinaryTreeTester :: doTreeStuff()
{
    testTree.insert(7);
    testTree.insert(1);
    testTree.insert(24);
    testTree.insert(6);
    testTree.insert(66);
    testTree.insert(5);
    testTree.insert(25);
    testTree.insert(4380);
    testTree.insert(99);
    testTree.insert(9001);
    testTree.insert(101);
    
    testTree.inOrderTraversal();
}

template <class Type>
void BinarySearchTree<Type> :: preOrderTraversal()
{
    preOrderTraversal(this->root);
}

template <class Type>
void BinarySearchTree<Type> :: preOrderTraversl(BinaryTreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        cout << currentNode->getData() << endl;
        preOrderTraversal(currentNode->getLeftChild());
        preOrderTraversal(currentNode->getRightChild());
    }
    
}

template <class Type>
void BinarySearchTree<Type> :: postOrderTraversal()
{
    postOrderTraversal(this->root);
}

template <class Type>
void BinarySearchTree<Type> :: postOrderTraversl(BinaryTreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        postOrderTraversal(currentNode->getLeftChild());
        postOrderTraversal(currentNode->getRightChild());
        cout << currentNode->getData() << endl;
    }
    
}

template <class Type>
int BinarySearchTree<Type> :: getSize()
{
    int size = 0;
    
    size += calculateSize(this->root);
    
    return size;
}

template <class Type>
int BinarySearchTree<Type> :: calculateSize(BinaryTreeNode<Type> * current)
{
    if(current != nullptr)
    {
        return calculateSize(current->ageLeftChild()) + calculateSize(current->getRightChild()) + 1;
    }
    return 0;
}

template <class Type>
int BinarySearchTree<Type> :: getHeight()
{
    size += calculateSize(this->root);
}

template <class Type>
int BinarySearchTree<Type> :: calculateHeight(BinaryTreeNode<Type> * current)
{
    if(current != nullptr)
    {
        return max (calculateHeight(current->ageLeftChild()) + calculateHeight(current->getRightChild()) + 1;
    }
    return 0;
}
        
template <class Type>
bool BinarySearchTree<Type> :: isBalanced()
{
    return isBalanced(this->root);
}
        
        
template <class Type>
bool BinarySearchTree<Type> :: isBalanced(BinaryTreeNode<Type> * current)
{
    int leftHeight = 0;
    int rightHeight = 0;
    
    if(current == nullptr)
    {
        return true;
    }
    
    leftHeight = calculateHeight(current->getLeftChild());
    righttHeight = calculateHeight(current->getLeftChild());
    
    int heightDifference = abs(leftHeight - rightHeight);
    bool leftBalanced = isBalanced(current->getLeftChild());
    bool righttBalanced = isBalanced(current->getRightChild());
    
    if (heightDifference <= 1 && leftBalanced && rightBalanced)
    {
        reuturn true;
    }
    
    return false;
}
        
template <class Type>
bool BinarySearchTree<Type> :: is Completed()
{
    int index = 0;
    int size = getSize();
    
    return isComplete(this->root, index, size);
}
        
template<class Type>
bool BinarySearchTree<Type> :: isComplete(BinaryTreeNode<Type> * startNode, int index, int size)
{
    if(startNode == nullptr)
    {
        return true;
    }

    if(index >= size)
    {
        return false;
    }
    return (isComplete[startNode->getLeftChil[], 2 * index + 1, size) && isComplete(startNode->getRightChild(), 2 * index * 2, size));
}
    
    template <class Type>
    bool BinarySearchTree<Type> :: contains(Type itemToFind)
    {
    BinaryTreeNode<Type> * current = this->root;
    if(current == nullptr)
    {
        return false;
    }
    else
    {
        while(current != nullptr)
        {
            if(itemToFind == current->getData())
        {
            return true;
        }
        else if (itemToFind < current->getData())
        {
            current = current->getLeftNode();
        }
        else
        {
            current = current->getRighNode();
        }
    }
    return false;
  }
    
}
    
template <class Type>
void BinarySearchTree<Type> :: remove(Type getRidOfMe)
{
    if(this->root == nullptr)
    {
    cout << "Empty tree so removal is not possible" << endl;
    }
    else
    {
        BinaryTreeNode<Type> * current = this->root;
        BinaryTreeNode<Type> * previous = nullptr;
        bool hasBeenFound = false;
    
        while(current != nullptr && !hasBeenFound)
        {
            if(current -> getData() == getRidOfMe)
            {
                hasBeenFound = true;
            }
            else
            {
                previous = current;
                if(getRidOfMe < current->getData())
                {
                       current = current->getLeftNode();
                }
                else
                {
                       current = current->getRightNode();
                }
            }
    }
    
            if(current == nullptr)
            {
                cerr << "Item not found, removal unsuccessful" <<< endl;
            }
            else if(hasBeenFound)
            {
                if(current == this->root)
                {
                    removeNode(this->root);
                }
            else if(getRidOfMe < previous->getData())
            {
                removeNode(previous->getLeftNode());
            }
            else
            {
                removeNode(previous->getRightNode());
            }
        }
    }
}
    template <class Type>
    void BinarySearchTree<Type> :: removeNode(BinaryTreeNode<Type> * removeMe)
    {
        BinaryTreeNode<Type> * current;
        BinaryTreeNode<Type> * previous;
        BinaryTreeNode<Type> * temp;
    
        previous = removeMe->getRootNode();
    //Node is a leaf - has no kiddos
    if(removeMe->getRightNode() == nullptr && removeMe->getLeftNode() == nullptr)
    {
        temp = removeMe;
        removeMe = nullptr;
    
        if(previous != nullptr && removeMe->getData() < previous->getData())
        {
            previous->setLeftNode(removeMe);
        }
        else if(previous != nullptr && removeMe->getData() > previous->getData())
        {
            previous->setRightNode(removeMe);
        }
        delete temp;
    }
    
    //Node has only a left child
    else if(removeMe->getRightNode() == nullptr)
    {
       temp = removeMe;
       removeMe = removeMe->getLeftNode();
    
       if(previous != nullptr && temp->getData() < previous->getData())
       {
           previous->setLeftNode(removeMe);
       }
       else if(previous != nullptr && temp->getData() > previous->getData())
       {
        previous->setRightNode(removeMe);
       }
    
        removeMe->setRootNode(previous);
                       
        delete temp;
    }
    
    //Node has only a right child
    else if(removeMe->getLeftNode() == nullptr)
    {
        temp = removeMe;
        removeMe = removeMe->getRightNode();
                       
    if(previous != nullptr && temp->getData() < previous->getData())
    {
        previous->setLeftNode(removeMe);
    }
    else if(previous != nullptr && temp->getData() > previous->getData())
    {
        previous->setRightNode(removeMe);
    }
                       
        removeMe->setRootNode(previous);
                       
        delete temp;
    }
    
//Node has both children
    else
    {
        current = getRightMostChild(removeMe->getLeftNode());
        previous = current->getRootNode();
        removeMe->setData(current->getData());
    
        if(previous == nullptr)//removing fromt he root
        {
            removeMe->setLeftNode(current->getLeftNode());
        }
        else
        {
            previous->setRightNode(current-> getLeftNode());
        }
        if(current->getLeftNode() != nullptr)
        {
            current->getLeftNode()->setRootNode(removeMe);
        }
        delete current;
    }
    
        if(removeMe == nullptr || removeMe->getRootNode() == nullptr)
        {
            this->root = removeMe;
        }
    }
    
    template <class Type>
    BinaryTreeNode<Type> * BinarySearchTree<Type> :: getLeftMosChild(BinaryTreeNode<Type> * startNode)
    {
        BinaryTreeNode<Type> * currentNode = startingNode;
        BinaryTreeNode<Type> * previous = nullptr;
        while (currentNode != nullptr;
        {
            previous = currentNode;
            currentNode = currentNode->getLeftNode();
        }
        return previous;
    }
    
    template <class Type>
    BinaryTreeNode<Type> * BinarySearchTree<Type> :: getRightMosChild(BinaryTreeNode<Type> * startNode)
    {
        BinaryTreeNode<Type> * currentNode = startingNode;
        BinaryTreeNode<Type> * previous = nullptr;
        while (currentNode != nullptr;
            {
                previous = currentNode;
                currentNode = currentNode->getLeftNode();
            }
            return previous;
        }
    
    template <class Type>
    Type BinarySearchTree<Type> :: findMaximum()
    {
        assert(this->root != nullptr);
        return getRigtMostChild(this->root)->getData();
    }
    template <class Type>
    Type BinarySearchTree<Type> :: findMinimum()
    {
        assert(this->root != nullptr);
        return getLeftMostChild(this->root)->getData();
    }
        
    void destroyTree(BinaryTreeNode<Type> * node);
        
    template <class Type>
    BinarySearchTree<Type> :: ~BinarySearchTree()
    {
        destroyTree(this->root);
    }
            
    template <class Type>
    void BinarySearchTree<Type> :: destroyTree(BinaryTreeNode<Type> * node)
    {
        if(node != nullptr)
        {
            destroyTree(node->getLeftNode());
            destroyTree(node->getRightNode());
            delete node;
        }
    }
                   
            
    
#endif /* BinarySearchTree_h */
