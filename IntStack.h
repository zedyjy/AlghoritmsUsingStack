//
// Created by zeynep doğa dellal on 14.05.2022.
//

#ifndef UNTITLED_INTSTACK_H
#define UNTITLED_INTSTACK_H

#include <iostream>
using namespace std;
class IntStack {

public:
    IntStack();
    IntStack(const IntStack& aStack);
    ~IntStack();

    bool isEmpty() const;
    bool push(int newItem);
    bool pop();
    bool pop(int& stackTop);
    bool getTop(int& stackTop) const;
    int top();
    void peek(int index, int value);

private:
    struct StackNode {            // a node on the stack
        int item;        // a data item on the stack
        StackNode* next;        // pointer to next node
    };

    StackNode* topPtr;     // pointer to first node in the stack
};

#endif //UNTITLED_STACKDOUBLE_H

