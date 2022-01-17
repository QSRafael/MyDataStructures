#include "Node.h"

class LinkedList
{
private:
    Node *head;

public:
    LinkedList();
    ~LinkedList();
    int operator[](int);
    Node *getHead();
    void append(int);
    void push(int);
    void deleteValue(int);
    void deletePosition(int);
    void deleteAllNodes();
    void print();
    size_t size();
    bool inList(int);
    void middle();
    int count(int);
    void createLoopInPosition(int);
    int loopSize();
    LinkedList *reverseList();
    bool isPalindrome();
    void removeDuplicates();
    void swap(int, int);
};
