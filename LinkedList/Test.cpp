#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList list;
    LinkedList list2;
    LinkedList list3;

    for (int i = 0; i < 10; i++)
    {
        list.append(i);
        list2.push(i);
    }

    list.print();
    list2.print();
    list3.print();
    list + list2;
    list.print();
    list2.print();
    list3.print();
}
