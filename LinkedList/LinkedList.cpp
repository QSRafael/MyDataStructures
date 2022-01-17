#include <iostream>
#include <unordered_set>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList()
{
    head = nullptr;
}

LinkedList::~LinkedList()
{
    deleteAllNodes();
}

int LinkedList::operator[](int i)
{
    Node *control = head;
    for (int j = 0; j < i; j++)
    {
        control = control->getNext();
    }
    return control->getData();
}

Node *LinkedList::getHead()
{
    return head;
}

void LinkedList::append(int d)
{
    Node *novo = new Node(d);
    Node *control = head;
    if (head == nullptr)
    {
        head = novo;
        return;
    }

    while (control->getNext() != nullptr)
    {
        control = control->getNext();
    }
    control->setNext(novo);
}

void LinkedList::push(int d)
{
    Node *novo = new Node(d);
    novo->setNext(head);
    head = novo;
}

void LinkedList::deleteValue(int d)
{
    Node *control = head;
    Node *aux;
    if (control->getData() == d)
    {
        head = control->getNext();
        delete control;
        return;
    }
    while (control->getNext() != nullptr)
    {
        if (control->getNext()->getData() == d)
        {
            aux = control->getNext();
            control->setNext(control->getNext()->getNext());
            delete aux;
            return;
        }
        control = control->getNext();
    }
}

void LinkedList::deletePosition(int i)
{
    Node *control = head;
    Node *aux;
    if (i == 0)
    {
        head = control->getNext();
        delete control;
        return;
    }
    for (int j = 0; j < i - 1; j++)
    {
        control = control->getNext();
        if (control->getNext() == nullptr)
            return;
    }

    aux = control->getNext();
    control->setNext(control->getNext()->getNext());
    delete aux;
    return;
}

void LinkedList::deleteAllNodes()
{
    Node *aux;
    while (head != nullptr)
    {
        aux = head;
        head = head->getNext();
        delete aux;
    }
}

void LinkedList::print()
{
    Node *control = head;
    if (head != nullptr)
    {
        while (control != nullptr)
        {
            cout << "(" << control->getData() << ")->";
            control = control->getNext();
        }
    }
    cout << "(null)" << endl;
}

size_t LinkedList::size()
{
    Node *control = head;
    size_t count = 0;
    while (control != nullptr)
    {
        control = control->getNext();
        count++;
    }
    return count;
}

bool LinkedList::inList(int d)
{
    Node *control = head;
    while (control != nullptr)
    {
        if (control->getData() == d)
            return true;
        control = control->getNext();
    }
    return false;
}

void LinkedList::middle()
{
    Node *slow = head;
    Node *fast = head;
    if (head != nullptr)
    {
        while (fast != nullptr)
        {
            if (fast->getNext() == nullptr)
                break;
            slow = slow->getNext();
            fast = fast->getNext()->getNext();
        }
        cout << slow->getData() << endl;
    }
}

int LinkedList::count(int d)
{
    Node *control = head;
    int count = 0;

    while (control != nullptr)
    {
        if (control->getData() == d)
            count++;
        control = control->getNext();
    }
    return count;
}

void LinkedList::createLoopInPosition(int i) // usar com cuidado
{
    Node *target = nullptr;
    Node *control = head;
    int count = 0;
    while (control->getNext() != nullptr)
    {
        if (count == i)
            target = control;
        control = control->getNext();
        count++;
    }
    control->setNext(target);
}

int LinkedList::loopSize()
{
    Node *fast = head;
    Node *slow = head;
    int count = 0;
    while (fast != nullptr && slow != nullptr && fast->getNext() != nullptr)
    {
        slow = slow->getNext();
        fast = fast->getNext()->getNext();
        if (slow == fast)
        {
            do
            {
                slow = slow->getNext();
                count++;
            } while (slow != fast);
            return count;
        }
    }
    return 0;
}

LinkedList *LinkedList::reverseList()
{
    Node *control = head;
    LinkedList *newlist = new LinkedList();
    while (control != nullptr)
    {
        newlist->push(control->getData());
        control = control->getNext();
    }
    return newlist;
}

bool LinkedList::isPalindrome()
{
    LinkedList *aux = reverseList();
    Node *control1 = head;
    Node *control2 = aux->getHead();
    aux->print();
    while (control1 != nullptr)
    {
        if (control1->getData() != control2->getData())
            return false;
        control1 = control1->getNext();
        control2 = control2->getNext();
    }
    return true;
}

void LinkedList::removeDuplicates()
{
    unordered_set<int> set;
    Node *control = head;
    Node *prev = nullptr;
    while (control != nullptr)
    {
        if (set.find(control->getData()) != set.end())
        {
            prev->setNext(control->getNext());
            delete control;
            control = prev;
        }
        else
        {
            set.insert(control->getData());
            prev = control;
        }
        control = control->getNext();
    }
}

void LinkedList::swap(int d1, int d2)
{
    Node *control = head;
    Node *prev1 = nullptr;
    Node *current1 = nullptr;
    Node *prev2 = nullptr;
    Node *current2 = nullptr;
    int count = 0;

    if (control->getData() == d1)
    {
        prev1 = nullptr;
        current1 = control;
    }
    if (control->getData() == d2)
    {
        prev2 = nullptr;
        current2 = control;
    }

    while (control->getNext() != nullptr)
    {

        if (control->getNext()->getData() == d1)
        {
            prev1 = control;
            current1 = control->getNext();
        }
        if (control->getNext()->getData() == d2)
        {
            prev2 = control;
            current2 = control->getNext();
        }
        if (prev1 != nullptr && prev2 != nullptr)
            break;

        control = control->getNext();
    }

    if (current1 == nullptr || current2 == nullptr)
        return;

    if (prev1 != nullptr)
        prev1->setNext(current2);
    else
        head = current2;

    if (prev2 != nullptr)
        prev2->setNext(current1);
    else
        head = current1;

    control = current2->getNext();
    current2->setNext(current1->getNext());
    current1->setNext(control);
}