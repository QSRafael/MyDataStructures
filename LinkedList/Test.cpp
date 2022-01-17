#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList list;

    for (int i = 0; i < 10; i++)
    {
        list.append(i);
    }

    list.print();
    list.segregateEvenOdd();
    list.print();

}
