//
// Created by zeynep doğa dellal on 13.05.2022.
//

#ifndef UNTITLED_STACKCHAR_H
#define UNTITLED_STACKCHAR_H
#include<string>

#include <iostream>
using namespace std;
class StackChar {

public:
    StackChar();
    StackChar(const StackChar& aStack);
    ~StackChar();

    bool isEmpty() const;
    bool push(char newItem);
    bool pop();
    bool pop(char& stackTop);
    bool getTop(char& stackTop) const;

private:
    struct StackNode {            // a node on the stack
        char item;        // a data item on the stack
        StackNode* next;        // pointer to next node
    };

    StackNode* topPtr;     // pointer to first node in the stack
};



#endif //UNTITLED_STACKCHAR_H
