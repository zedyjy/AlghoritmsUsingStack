//
// Created by zeynep doğa dellal on 13.05.2022.
//
#include <iostream>
using namespace std;
#include "StackDouble.h"
StackDouble::StackDouble() : topPtr(NULL) {
}

StackDouble::StackDouble(const StackDouble& aStack)
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

StackDouble::~StackDouble()
{
    // pop until stack is empty
    while (!isEmpty())
        pop();

}

bool StackDouble::isEmpty() const
{
    return topPtr == NULL;

}

bool StackDouble::push(double newItem)
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

bool StackDouble::pop()
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

bool StackDouble::pop(double& stackTop)
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

bool StackDouble::getTop(double& stackTop) const
{

    if (isEmpty())
        return false;

        // stack is not empty; retrieve top
    else {
        stackTop = topPtr->item;
        return true;
    }

}

double StackDouble::top() {
    return topPtr->item;
}
