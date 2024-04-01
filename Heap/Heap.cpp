#include "Heap.h"

template<typename T>
Heap<T>::Heap() : heapSize(0) {}

template<typename T>
Heap<T>::~Heap() {}

template<typename T>
void Heap<T>::insert(const T& value) {
    heapArray.push_back(value);
    heapSize++;
    heapifyUp(heapSize - 1);
}

template<typename T>
void Heap<T>::heapifyUp(int index) {
    while (index > 0 && heapArray[(index - 1) / 2] < heapArray[index]) {
        std::swap(heapArray[(index - 1) / 2], heapArray[index]);
        index = (index - 1) / 2;
    }
}

template<typename T>
T Heap<T>::extractMax() {
    if (isEmpty()) {
        throw std::out_of_range("Heap is empty");
    }
    T max = heapArray[0];
    heapArray[0] = heapArray[heapSize - 1];
    heapArray.pop_back();
    heapSize--;
    heapifyDown(0);
    return max;
}

template<typename T>
void Heap<T>::heapifyDown(int index) {
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < heapSize && heapArray[leftChild] > heapArray[largest]) {
        largest = leftChild;
    }

    if (rightChild < heapSize && heapArray[rightChild] > heapArray[largest]) {
        largest = rightChild;
    }

    if (largest != index) {
        std::swap(heapArray[index], heapArray[largest]);
        heapifyDown(largest);
    }
}

template<typename T>
const T& Heap<T>::peekMax() const {
    if (isEmpty()) {
        throw std::out_of_range("Heap is empty");
    }
    return heapArray[0];
}

template<typename T>
bool Heap<T>::isEmpty() const {
    return heapSize == 0;
}

template<typename T>
int Heap<T>::size() const {
    return heapSize;
}