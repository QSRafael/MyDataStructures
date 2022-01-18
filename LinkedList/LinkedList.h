/*
 * Rafael de Queiroz Souza
 * rfl.dqs@gmail.com
 */

#include <iostream>
#include <unordered_set>
#include "Node.h"
#define self (*this)
using namespace std;

template <typename T>
class LinkedList
{
private:
    Node<T> *head;

public:
    LinkedList() { head = nullptr; };
    ~LinkedList() { deleteAllNodes(); };
    Node<T> *operator()(int);            // retorna um ponteiro para o elemento i
    T operator[](int);                   // retorna o valor do elemento i
    void operator+(LinkedList &);        // concatena duas listas
    Node<T> *getHead() { return head; }; // retorna a cabeça da lista
    void append(T);                      // adiciona no fim
    void push(T);                        // adiciona na frente
    void deleteValue(T);                 // deleta a primeira ocorrência de um valor
    void deletePosition(int);            // deleta o nó na posição i
    void deleteAllNodes();
    void print();
    size_t size();
    bool inList(T);                 // verifica se a lista contém o valor i
    void middle();                  // retorna o elemento central
    int count(T);                   // conta quantas vezes o elemento i aparece
    void createLoopInPosition(int); // usar com cautela... apenas para testes
    int loopSize();
    LinkedList *reverseList(); // cria uma nova lista com a ordem reversa da anterior
    bool isPalindrome();
    void removeDuplicates();
    void swap(T, T);                 // troca dois valores de lugar
    void swap(Node<T> *, Node<T> *); // troca dois nós de lugar
    void sort();                     // ordena usando quicksort
    void quicksort(int, int);
    void segregateEvenOdd(); // separa os pares dos ímpares
    void reverse();          // reverte a lista inplace
};

template <typename T>
Node<T> *LinkedList<T>::operator()(int i) // retorna um ponteiro para o elemento i
{
    Node<T> *control = head;
    for (int j = 0; j < i; j++)
        control = control->getNext();
    return control;
}

template <typename T>
T LinkedList<T>::operator[](int i) // retorna o valor do elemento i
{
    Node<T> *control = head;
    for (int j = 0; j < i; j++)
        control = control->getNext();
    return control->getData();
}

template <typename T>
void LinkedList<T>::operator+(LinkedList &list)
{
    Node<T> *control = list.getHead();
    while (control != nullptr)
    {
        append(control->getData());
        control = control->getNext();
    }
}

template <typename T>
void LinkedList<T>::append(T d)
{
    Node<T> *novo = new Node<T>(d);
    Node<T> *control = head;
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

template <typename T>
void LinkedList<T>::push(T d)
{
    Node<T> *novo = new Node<T>(d);
    novo->setNext(head);
    head = novo;
}

template <typename T>
void LinkedList<T>::deleteValue(T d)
{
    Node<T> *control = head;
    Node<T> *aux;
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

template <typename T>
void LinkedList<T>::deletePosition(int i)
{
    Node<T> *control = head;
    Node<T> *aux;
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

template <typename T>
void LinkedList<T>::deleteAllNodes()
{
    Node<T> *aux;
    while (head != nullptr)
    {
        aux = head;
        head = head->getNext();
        delete aux;
    }
}

template <typename T>
void LinkedList<T>::print()
{
    Node<T> *control = head;
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

template <typename T>
size_t LinkedList<T>::size()
{
    Node<T> *control = head;
    size_t count = 0;
    while (control != nullptr)
    {
        control = control->getNext();
        count++;
    }
    return count;
}

template <typename T>
bool LinkedList<T>::inList(T d)
{
    Node<T> *control = head;
    while (control != nullptr)
    {
        if (control->getData() == d)
            return true;
        control = control->getNext();
    }
    return false;
}

template <typename T>
void LinkedList<T>::middle()
{
    Node<T> *slow = head;
    Node<T> *fast = head;
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

template <typename T>
int LinkedList<T>::count(T d)
{
    Node<T> *control = head;
    int count = 0;

    while (control != nullptr)
    {
        if (control->getData() == d)
            count++;
        control = control->getNext();
    }
    return count;
}

template <typename T>
void LinkedList<T>::createLoopInPosition(int i) // usar com cuidado
{
    Node<T> *target = nullptr;
    Node<T> *control = head;
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

template <typename T>
int LinkedList<T>::loopSize()
{
    Node<T> *fast = head;
    Node<T> *slow = head;
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

template <typename T>
LinkedList<T> *LinkedList<T>::reverseList()
{
    Node<T> *control = head;
    LinkedList *newlist = new LinkedList();
    while (control != nullptr)
    {
        newlist->push(control->getData());
        control = control->getNext();
    }
    return newlist;
}

template <typename T>
bool LinkedList<T>::isPalindrome()
{
    LinkedList *aux = reverseList();
    Node<T> *control1 = head;
    Node<T> *control2 = aux->getHead();
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

template <typename T>
void LinkedList<T>::removeDuplicates()
{
    unordered_set<int> set;
    Node<T> *control = head;
    Node<T> *prev = nullptr;
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

template <typename T>
void LinkedList<T>::swap(T d1, T d2)
{
    Node<T> *control = head;
    Node<T> *prev1 = nullptr;
    Node<T> *current1 = nullptr;
    Node<T> *prev2 = nullptr;
    Node<T> *current2 = nullptr;

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

template <typename T>
void LinkedList<T>::swap(Node<T> *n1, Node<T> *n2)
{
    Node<T> *control = head;
    Node<T> *prev1 = nullptr;
    Node<T> *current1 = nullptr;
    Node<T> *prev2 = nullptr;
    Node<T> *current2 = nullptr;

    if (control == n1)
    {
        prev1 = nullptr;
        current1 = control;
    }
    if (control == n2)
    {
        prev2 = nullptr;
        current2 = control;
    }

    while (control->getNext() != nullptr)
    {

        if (control->getNext() == n1)
        {
            prev1 = control;
            current1 = control->getNext();
        }
        if (control->getNext() == n2)
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

template <typename T>
void LinkedList<T>::sort()
{
    if (head == nullptr)
        return;

    quicksort(0, size());
}

template <typename T>
void LinkedList<T>::quicksort(int begin, int end)
{
    int i = begin;
    int j = end - 1;
    int pivo = self[(begin + end) / 2];
    while (i <= j)
    {
        while (self[i] < pivo && i < end)
            i++;

        while (self[j] > pivo && j > begin)
            j--;

        if (i <= j)
        {
            swap(self(i), self(j));
            i++;
            j--;
        }
    }
    if (j > begin)
        quicksort(begin, j + 1);
    if (i < end)
        quicksort(i, end);
}

template <typename T>
void LinkedList<T>::segregateEvenOdd()
{
    Node<T> *control = head;
    int aux;
    size_t s = size();
    for (size_t i = 0; i < s; i++)
    {
        aux = control->getData();
        control = control->getNext();
        if (aux % 2 != 0)
        {
            append(aux);
            deleteValue(aux);
        }
    }
}

template <typename T>
void LinkedList<T>::reverse()
{
    Node<T> *control = head;
    Node<T> *next = nullptr;
    Node<T> *prev = nullptr;
    while (control != nullptr)
    {
        next = control->getNext();
        control->setNext(prev);
        prev = control;
        control = next;
    }
    head = prev;
}
