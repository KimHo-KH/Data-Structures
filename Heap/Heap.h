#ifndef HEAP_H
#define HEAP_H

#include <vector>

template<typename T>
class Heap {
private:
    std::vector<T> heapArray;
    int heapSize;

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    Heap();
    ~Heap();

    void insert(const T& value);
    T extractMax();
    const T& peekMax() const;
    bool isEmpty() const;
    int size() const;
};

#include "Heap.cpp" // Include the implementation file because it's a template class

#endif // HEAP_H