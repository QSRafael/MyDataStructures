template <typename T>
class Node
{
private:
    Node *next;
    T data;

public:
    Node(T d);
    ~Node();
    Node *getNext();
    void setNext(Node *);
    T getData();
};

template <typename T>
Node<T>::Node(T d)
{
    data = d;
    next = nullptr;
}

template <typename T>
Node<T>::~Node()
{
}

template <typename T>
Node<T> *Node<T>::getNext()
{
    return next;
}

template <typename T>
void Node<T>::setNext(Node *point)
{
    next = point;
}

template <typename T>
T Node<T>::getData()
{
    return data;
}
