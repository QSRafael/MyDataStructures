#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.append(6);
    list.append(7);
    list.append(8);
    list.append(9);
    
    list.print();

    list.swap(list(2), list(2));
    list.print();
    
    list.swap(list(0),list(1));
    list.print();
    
    list.swap(list(0),list(8));
    list.print();
    
    list.swap(2,7);
    list.print();

    cout << list(3)->getData();
    cout << list[4];
    return 0;
}
