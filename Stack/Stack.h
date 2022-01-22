#include "../LinkedList/LinkedList.h"

template <typename T>
class Stack
{
private:
    LinkedList<T> *base;

public:
    Stack();
    ~Stack(){};
    void push(T);
    T pop();
    T top();
    bool isEmpty();
};

template <typename T>
Stack<T>::Stack()
{
    LinkedList<T> *nova = new LinkedList<T>();
    base = nova;
}

template <typename T>
void Stack<T>::push(T d)
{
    base->push(d);
}

template <typename T>
T Stack<T>::pop()
{
    T d = base->operator[](0);
    base->deletePosition(0);
    return d;
}

template <typename T>
T Stack<T>::top()
{
    return base->operator[](0);
}

template <typename T>
bool Stack<T>::isEmpty()
{
    return base->operator()(0) == nullptr;
}
