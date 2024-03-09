#ifndef STACK_H
#define STACK_H

class Stack {
private:
    int *arr;
    int size;
    int top;

public:
    Stack();
    Stack(const Stack &other);
    ~Stack();

    void push(int elem);
    int pop();
    bool isEmpty();
    void multiPop(int N);
    void show();

    Stack& operator=(const Stack &other);
};

#endif
