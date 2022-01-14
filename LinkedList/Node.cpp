#include "Node.h"

Node::Node(int d)
{
    data = d;
    next = nullptr;
}

Node::~Node()
{
}

Node *Node::getNext()
{
    return next;
}

void Node::setNext(Node *point)
{
    next = point;
}

int Node::getData()
{
    return data;
}
