//
// Created by zeynep doğa dellal on 13.05.2022.
//

#ifndef UNTITLED_STACKDOUBLE_H
#define UNTITLED_STACKDOUBLE_H

#include <iostream>
using namespace std;
class StackDouble {

public:
    StackDouble();
    StackDouble(const StackDouble& aStack);
    ~StackDouble();

    bool isEmpty() const;
    bool push(double newItem);
    bool pop();
    bool pop(double& stackTop);
    bool getTop(double& stackTop) const;
    double top();

private:
    struct StackNode {            // a node on the stack
        double item;        // a data item on the stack
        StackNode* next;        // pointer to next node
    };

    StackNode* topPtr;     // pointer to first node in the stack
};

#endif //UNTITLED_STACKDOUBLE_H
