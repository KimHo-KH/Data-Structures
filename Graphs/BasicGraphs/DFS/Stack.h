#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {
private:
    static const int MAX_SIZE = 1000;
    T data[MAX_SIZE];
    int top;

public:
    Stack();
    bool isEmpty() const;
    bool isFull() const;
    void push(const T& item);
    T pop();
    T peek() const;
};

#include "Stack.cpp" // Include the implementation file because it's a template class

#endif // STACK_H