#ifndef QUEUE_H
#define QUEUE_H

template<typename T>
class Queue {
private:
    static const int MAX_SIZE = 1000;
    T data[MAX_SIZE];
    int front;
    int rear;
    int count;

public:
    Queue();
    bool isEmpty() const;
    bool isFull() const;
    void enqueue(const T& item);
    T dequeue();
    T peek() const;
};

#include "Queue.cpp" // Include the implementation file because it's a template class

#endif // QUEUE_H