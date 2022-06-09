//
// Created by zeynep doğa dellal on 13.05.2022.
//

#ifndef UNTITLED_SOLUTIONS_H
#define UNTITLED_SOLUTIONS_H
#include <iostream>
#include<string>
#include "IntStack.h"

using namespace std;
void fantabulous(const string list, int length);
void subset(const string intervals, int length);
string infix2prefix(const string expression);
string infix2prefixvol2(const string expression);
void evaluatePrefix(const string expression);
void evaluateInputPrefixExpression();
IntStack changeStringToStack(string list, int length);
void checkIfTrue(int*arr,int length);
bool checkBracets(const string s);
double evaluatePrefixvol2(const string exp);

class Solutions {
public:
    Solutions();
    ~Solutions();

private:
};



#endif //UNTITLED_SOLUTIONS_H
