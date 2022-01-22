/*
 * Rafael de Queiroz Souza
 * rfl.dqs@gmail.com
 */

template <typename T>
class Node
{
private:
    Node *next; // ponteiro para o próximo elemento
    T data;     // dado

public:
    Node(T d);
    ~Node(){};
    Node *getNext() { return next; };
    void setNext(Node *point) { next = point; };
    T getData() { return data; };
};

template <typename T>
Node<T>::Node(T d)
{
    data = d;
    next = nullptr;
}
