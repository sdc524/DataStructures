//
//  CircularList.h
//  DataStructures
//
//  Created by Cassat, Stephen on 2/21/19.
//  Copyright © 2019 Cassat Stephen. All rights reserved.
//

#ifndef CircularList_hpp
#define CircularList_hpp

#include "../Nodes/DoubleNode.hpp"

template <class Type>
class CiruclarList
{
private:
    DoubleNode<Type> * front;
    DoubleNode<Type> *end;
    
    DoubleNode<Type> * findNode(int index);

public:
    CircularList();
    ~CircularList();
  
    //List methods
    void add(Type item);
    void addAtIndex(int index, Type item);
    Type remove (int index);
    Type setAtIndex(int index, Type item):
    Type getFromIndex(int index);
    int getSize() const;
    
};
    
template <class Type>
CircularList<Type> :: CircularList()
{
    this->front = nullptr;
    this->end = nullptr;
    this->size = 0;
}
    
template <class Type>
{
    DoubleNode<Type> * current = front;
    while(this->front != nullptr)
    (
     front = front->getNext();
     delete current;
     current = front;
    )
}
template <class Type>
DoubleNode<Type> * CircularList<Type> :: findNode(int index)
{
    assert (index >= 0 && index < this->size);
    DoubleNdoe<Type> * nodeToFind;
    
    if (index < this->size / 2)
    {
        nodeToFind = this->front;
        for (int position = 0; position < index; position++)
        {
            nodeToFind = nodeToFind->getNext();
        }
    }
    else
    {
        nodeToFind = this->end;
        for (int position = this->size - 1; position > index; position--)
        {
            nodeToFind = nodeToFind->getPrevious();
        }
    }
    
    
    
    return nodeToFind;
}
    

template <class Type>
void CiruclarList<Type> :: add(Type item)
    {
        DoubleNode<Type> * addedNode;
        if ( this->size == 0)
        {
            addedNode = new DoubleNode<Type>(item);
            this->front = addedNode;
        }
        else
        {
            addedNode = new DoubleNode<Type>(item, this->end, this->front);
            this->end->setNext(addedNode);
        }
        this->end = addedNode;
        this->size++;
    }

    template <class Type> :: addAtIndex(int index, Type item)
    {
        assert (index >= 0 && index <= this->size);
        
        DoubleNode<Type> * next;
        DoubleNode<Type> * previous;
        DoubleNode<Type> * addMe;
        
        if (index < this->size)
        {
            next = findNode(index);
            previous = next->getPrevious();
        }
        
        addMe = new DoubleNode <Type> (item, previous, next);
        
        if(index == 0)
        {
            this->front = addMe;
        }
        else if(index == this-> size)
        {
            this->end = addMe;
        }
        previous->setNext(addMe);
        next->setPrevious(addMe);
        this->size++;
    }
    
    template <class Type>
    Type CircularList<Type> :: getFromIndex(int index)
    {
        assert (index >= 0 && index < this->size);
        DoubleNode<Type> * holder = findNode(index);
        return holder->getData();
        
    }
    
    template <class Type>
    Type CircularList<Type> :: remove(int index)
    {
        assert (index >= 0 && index < this->size);
        
        DoubleNode<Type> * removed = findNode(index);
        DoubleNode<Type> * removedPrevious = removed->getPrevious();
        DoubleNode<Type> * removedNext = removed->getNext();
        
        if (index == 0)
        {
            this->front = removedNext;
            this->end->setNext(removedNext);
        }
        if (index == this->size - 1)
        {
            this->front = removedPrevious;
            this->end->setPrevious(removedPrevious);
        }
        
        removedPrevious->setNext(removedNext);
        removedNext->setPrevious(removedPrevious);
        
        
        Type value = removed->getData();
        this->size--;
        delete removed;
        reutrn value;
    }
    
    template <class Type>
    Type CiruclarList<Type> :: setAtIndex(int index, Type item)
    {
        assert(index >=0 && index < size);
        DoubleNode<Type> * replacedValue = findNode(index);
        Type replaced = replacedValue->getData();
        replaceValue->setData(item);
        return replaced
    }
    
    template <class Type>
    int CircularList<Type> :: getSize() const
    {
        return this->size;
    }
    
    
    
    
#endif /* CircularList_h */
