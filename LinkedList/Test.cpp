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

    list.swap(3,3);
    list.print();
    
    list.swap(1,2);
    list.print();
    
    list.swap(1,9);
    list.print();
    
    list.swap(2,7);
    list.print();
    return 0;
}
