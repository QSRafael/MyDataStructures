#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList list;
    for (int i = 0; i < 20; i++)
    {
        list.append(i);
        list.append(i);
        list.push(i);
    }
    
    list.print();
    list.removeDuplicates();
    list.print();
    return 0;
}
