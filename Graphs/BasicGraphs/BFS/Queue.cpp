#include "Queue.h"

template<typename T>
Queue<T>::Queue() : front(0), rear(-1), count(0) {}

template<typename T>
bool Queue<T>::isEmpty() const {
    return count == 0;
}

template<typename T>
bool Queue<T>::isFull() const {
    return count == MAX_SIZE;
}

template<typename T>
void Queue<T>::enqueue(const T& item) {
    if (isFull()) {
        throw std::runtime_error("Queue overflow");
    }
    rear = (rear + 1) % MAX_SIZE;
    data[rear] = item;
    count++;
}

template<typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        throw std::runtime_error("Queue underflow");
    }
    T item = data[front];
    front = (front + 1) % MAX_SIZE;
    count--;
    return item;
}

template<typename T>
T Queue<T>::peek() const {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    return data[front];
}