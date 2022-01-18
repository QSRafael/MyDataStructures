#include <iostream>
#include "LinkedList.cpp"
using namespace std;

int main()
{
    LinkedList<float> list;

    for (int i = 0; i < 10; i++)
    {
        list.append(i*2.4156);
    }

    list.print();
    list.reverse();
    list.print();
}
