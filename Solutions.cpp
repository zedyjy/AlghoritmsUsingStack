//
// Created by zeynep doğa dellal on 13.05.2022.
//

#include "Solutions.h"
#include "StackChar.h"
#include "StackDouble.h"
#include "IntStack.h"
#include <iostream>
#include<string>
#include <vector>
#include <sstream>

using namespace std;
int count;

Solutions::Solutions() {
}

Solutions::~Solutions() {

}

//void fantabulous(string list, int length) {
    //changeStringToStack(list,length);
    //cout<<count;
    //count =0;
//}
bool isFantabulous(IntStack test){ //FOR
    const int MIN_INT=-2147483647;
    int largest=MIN_INT;
    int secondLargest=MIN_INT;
    int largestIndex, secondLargestIndex;
    int i=0;
    while(!test.isEmpty()){
        int input;
        test.pop(input);
        if(input>largest){
            secondLargest=largest;
            secondLargestIndex=largestIndex;
            largest=input;
            largestIndex=i;
        }
        else if(input>secondLargest){
            secondLargest=input;
            secondLargestIndex=i;
        }
        i++;
    }

    if(secondLargestIndex>largestIndex){
        return true;
    }
    else{
        return false;
    }
}
void fantabulous(string list, int length){

    //GET THE NUMBERS FROM THE STRING INPUT

    //make the stack without commas
    IntStack numberArray;
    numberArray=changeStringToStack(list,length);

    //Find all the possible length sequences of the given array
    int finalFantabulousArrayCounter=0;
    for(int from=0; from<=length; from++){
        int count=0;
        for(int arLength=2; arLength+from<=length; arLength++){
            IntStack testedSequence;
            int count2=0;

            for(int i=from; i<from+arLength;i++){
                int value;
                numberArray.peek(i, value);
                testedSequence.push(value);
            }

            if(isFantabulous(testedSequence)) {
                finalFantabulousArrayCounter++;
            }
            count++;
        }
    }
    cout<<"The number of Fantabulous subsequences:"<<finalFantabulousArrayCounter<<endl;
}

//increments the count if true
void checkIfTrue(int*arr,int length){
    if(length<2) {

    }
    else {
        //if (second(arr, length) < largest(arr, length)) {
         //   count++;
        //}
    }
}

//This function makes the subarrays and calls the checkIfTrue function to check the fantabulous condition
void makeSubarrays(int*arr,int length){
    int* arr2 = new int [0];
    for(int i = 0; i<length;i++){
        for(int j = i;j<length;j++){
            int* arr2 = new int [j];
            int counter = 0;
            for(int k = i; k<j;k++){
                arr2[counter]=arr[k];
                counter++;
            }
            checkIfTrue(arr2,counter);
        }
    }
    delete[]arr2;
}

//This function changes string to stack and makes an array of the numbers in the list
IntStack changeStringToStack(string list, int length){
    vector <int> nums;
    std::stringstream list2(list);
    IntStack intStack;

    for(int i;list2>>i;){
        nums.push_back(i);
        if(list2.peek() == ','){
            list2.ignore();
        }
    }

    int * intArray = new int[nums.size()];
    for(int i = 0; i < nums.size();i++){
        intArray[i]=nums[i];
    }

    for(int i = 0; i<nums.size();i++){
        intStack.push(nums.at(i));
    }

    makeSubarrays(intArray,nums.size());
    return intStack;
}

void subset(string intervals, int length) {

}

string infix2prefix(string exp) {
    cout<<"Preix form of "<<exp<< " is: ";

    StackChar stack1;
    char a = ' ';
    char b = ' ';
    char c = ' ';
    char ch = ' ';
    char d = ' ';
    string prefix;
    string res;
    for (int i = exp.size() - 1; i >= 0; i--)
    {
        a = exp.at(i);
        if (a == '0' || a == '1' || a == '2' || a == '3' || a == '4' || a == '5' || a == '6' || a == '7' || a == '8' || a == '9') {
            prefix = prefix + a;
        }
        else if (a == ')') {
            stack1.push(a);
        }
        else if (a == '(') {
            stack1.pop(ch);
            while (ch != ')'){
                prefix = prefix + ch;
                stack1.pop(ch);
            }
        }
        else if (a == '-' || a == '+' || a == '*' || a == '/') {
            if (stack1.isEmpty())
            {
                stack1.push(a);
            }
            else {
                stack1.getTop(b);
                if ((b == '*' || b == '/') && (a == '+' || a == '-')) {
                    stack1.pop(b);
                    prefix = prefix + b;
                    stack1.push(a);
                }
                else {
                    stack1.push(a);
                }

            }
        }
    }

    while (!stack1.isEmpty()){
        stack1.pop(c);
        prefix = prefix + c;
    }
    for (int i = prefix.length() - 1; i >= 0; i--){
        res = res + prefix.at(i);
    }
    return res;
}

string infix2prefixvol2(string exp){
    StackChar stack1;
    char a = ' ';
    char b = ' ';
    char c = ' ';
    char ch = ' ';
    char d = ' ';
    string prefix;
    string res;
    for (int i = exp.size() - 1; i >= 0; i--)
    {
        a = exp.at(i);
        if (a == '0' || a == '1' || a == '2' || a == '3' || a == '4' || a == '5' || a == '6' || a == '7' || a == '8' || a == '9') {
            prefix = prefix + a;
        }
        else if (a == ')') {
            stack1.push(a);
        }
        else if (a == '(') {
            stack1.pop(ch);
            while (ch != ')'){
                prefix = prefix + ch;
                stack1.pop(ch);
            }
        }
        else if (a == '-' || a == '+' || a == '*' || a == '/') {
            if (stack1.isEmpty()){
                stack1.push(a);
            }
            else {
                stack1.getTop(b);
                if (b == '*' || b == '/' || b == '+' || b == '-') {
                    stack1.pop(b);
                    prefix = prefix + b;
                    stack1.push(a);
                }
                else {
                    stack1.push(a);
                }

            }
        }
    }

    while (!stack1.isEmpty()){
        stack1.pop(c);
        prefix = prefix + c;
    }
    for (int i = prefix.length() - 1; i >= 0; i--){
        res = res + prefix.at(i);
    }
    return res;
}

void evaluatePrefix(string exp) {

    StackDouble stack;
    double res = 0;
    for (int i = exp.size() - 1; i >= 0; i--) {
        char a = exp.at(i);
        if (a == '0' || a == '1' || a == '2' || a == '3' || a == '4' || a == '5' || a == '6' || a == '7' || a == '8' ||
            a == '9') {
            double b = a;
            b = b - '0';
            stack.push(b);
        } else {
            double digit1;
            double digit2;
            stack.pop(digit1);
            stack.pop(digit2);
            if (a == '+') {
                res = digit1 + digit2;
                stack.push(res);
            }
            if (a == '-') {
                res = digit1 - digit2;
                stack.push(res);
            }
            if (a == '*') {
                res = digit1 * digit2;
                stack.push(res);
            }
            if (a == '/') {
                res = digit1 / digit2;
                stack.push(res);
            }
        }
    }
    cout << "Result of " << exp << " is: " << res << endl;
}

double evaluatePrefixvol2(string exp){
    StackDouble stackDouble;
    double final=0;
    char a = ' ';
    for(int i = exp.length()-1;i>=0;i--){
        a = exp.at(i);
        if(a == '0' || a == '1' || a == '2' || a == '3' || a == '4' || a == '5' || a == '6' || a == '7' || a == '8' || a == '9'){
            double b = a;
            b=b-'0';
            stackDouble.push(b);
        }
        else{
            double digit1;
            double digit2;
            stackDouble.pop(digit1);
            stackDouble.pop(digit2);
            if(a == '+'){
                final=digit1+digit2;
                stackDouble.push(final);
            }
            else if(a == '-'){
                final=digit1-digit2;
                stackDouble.push(final);
            }
            else if(a == '*'){
                final=digit1*digit2;
                stackDouble.push(final);
            }
            else if(a == '/'){
                final=digit1/digit2;
                stackDouble.push(final);
            }
        }
    }
    return final;
}


bool checkBracets(string s){
    bool balanced = true;
    int i =0;
    StackChar stackChar;
    while (i<s.size()){
        if(s.at(i)=='{'){
            stackChar.push('{');
        }
        else if(s.at(i)=='}'){
            if(!stackChar.isEmpty()) {
                stackChar.pop();
            } else{
                balanced= false;
            }
        }
        i++;
    }
    if(stackChar.isEmpty()&&balanced){
        cout<<"true";
        balanced= true;
    }
    else{
        cout<<"false";
        balanced= false;
    }
    return balanced;
}