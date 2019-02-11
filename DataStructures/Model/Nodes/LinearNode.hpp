//
//  LinearNode.h
//  DataStructures
//
//  Created by Cassat, Stephen on 1/30/19.
//  Copyright © 2019 Cassat Stephen. All rights reserved.
//

#ifndef LinearNode_h
#define LinearNode_h

#include "Node.hpp"

template <class Type>
class LinearNode : public Node<Type>
{
private:
    LinearNode<Type> * next;
public:
    LinearNode();
    LinearNode(Type data);
    LinearNode(Type data, LinearNode<Type> * next);
    LinearNode<Type> * getNextNode();
    void setNextNode(LinearNode<Type> * next);
};

//Implementation of templates
template <class Type>
LinearNode<Type> :: LinearNode(): Node()
{}

template <class Type>
LinearNode<Type> :: LinearNode(Type data) : Node(data)
{
    this->next = nullptr;
}
template <class Type>
LinearNode<Type> :: LinearNode(Type data) : Node(data)
{
    this->next = next;
}

template <class Type>
LinearNode<Type> :: LinearNode(Type data) : Node(data)
{
    this->next = next;
}

template <class Type>
LinearNode<Type> :: LinearNode(Type data) : Node(data)
{
    this->next = next;
}

#endif /* LinearNode_h */
