//
// Created by zeynep doğa dellal on 14.05.2022.
//

#include "IntStack.h"
IntStack::IntStack() : topPtr(NULL) {
}

IntStack::IntStack(const IntStack& aStack)
{
    if (aStack.topPtr == NULL)
        topPtr = NULL;  // original stack is empty

    else {
        // copy first node
        topPtr = new StackNode;
        topPtr->item = aStack.topPtr->item;

        // copy rest of stack
        StackNode* newPtr = topPtr;
        for (StackNode* origPtr = aStack.topPtr->next;
             origPtr != NULL;
             origPtr = origPtr->next) {
            newPtr->next = new StackNode;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
        }
        newPtr->next = NULL;
    }

}

IntStack::~IntStack()
{
    // pop until stack is empty
    while (!isEmpty())
        pop();

}

bool IntStack::isEmpty() const
{
    return topPtr == NULL;

}

bool IntStack::push(int newItem)
{
    // create a new node
    StackNode* newPtr = new StackNode;

    // set data portion  of new node
    newPtr->item = newItem;

    // insert the new node
    newPtr->next = topPtr;
    topPtr = newPtr;

    return true;

}

bool IntStack::pop()
{
    if (isEmpty())
        return false;

        // stack is not empty; delete top
    else {
        StackNode* temp = topPtr;
        topPtr = topPtr->next;

        // return deleted node to system
        temp->next = NULL;  // safeguard
        delete temp;
        return true;
    }

}

bool IntStack::pop(int& stackTop)
{
    if (isEmpty())
        return false;

        // not empty; retrieve and delete top
    else {
        stackTop = topPtr->item;
        StackNode* temp = topPtr;
        topPtr = topPtr->next;

        // return deleted node to system
        temp->next = NULL;  // safeguard
        delete temp;
        return true;
    }

}

bool IntStack::getTop(int& stackTop) const
{

    if (isEmpty())
        return false;

        // stack is not empty; retrieve top
    else {
        stackTop = topPtr->item;
        return true;
    }

}

int IntStack::top() {
    return topPtr->item;
}
void IntStack::peek(int index, int value){
    int i=1;
    StackNode* node=topPtr;
    for(;node!=NULL;node=node->next){
        if(i==index){
            value= node->item;
        }
    }
}