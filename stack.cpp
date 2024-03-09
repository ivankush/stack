#include "stack.h"
#include <iostream>

Stack::Stack() : size(10), top(-1) {
    arr = new int[size];
}

Stack::Stack(const Stack &other) : size(other.size), top(other.top) {
    arr = new int[size];
    for (int i = 0; i <= top; ++i) {
        arr[i] = other.arr[i];
    }
}

Stack::~Stack() {
    delete[] arr;
}

void Stack::push(int elem) {
    if (top == size - 1) {
        int *tempArr = new int[size * 2];
        for (int i = 0; i <= top; ++i) {
            tempArr[i] = arr[i];
        }
        delete[] arr;
        arr = tempArr;
        size *= 2;
    }
    arr[++top] = elem;
}

int Stack::pop() {
    if (top == -1) {
        std::cerr << "Error: Stack is empty." << std::endl;
        return -1;
    }
    return arr[top--];
}

bool Stack::isEmpty() {
    return (top == -1);
}

void Stack::multiPop(int N) {
    for (int i = 0; i < N; ++i) {
        pop();
    }
}

void Stack::show() {
    for (int i = 0; i <= top; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

Stack& Stack::operator=(const Stack &other) {
    if (this != &other) {
        delete[] arr;
        size = other.size;
        top = other.top;
        arr = new int[size];
        for (int i = 0; i <= top; ++i) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}
