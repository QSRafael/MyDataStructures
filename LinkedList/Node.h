class Node
{
private:
    Node *next;
    int data;

public:
    Node(int d);
    ~Node();
    Node *getNext();
    void setNext(Node *);
    int getData();
};