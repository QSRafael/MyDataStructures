#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList list;

    for (int i = 0; i < 10; i++)
    {
        list.push(i);
        list.append(i);
        list.push(i*i/2);
    }

    list.print();
    list.sort();
    list.print();
    
}
