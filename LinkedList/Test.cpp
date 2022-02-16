/*
 * Rafael de Queiroz Souza
 * rfl.dqs@gmail.com
 */

#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    // criando listas
    LinkedList<int> list_int;
    LinkedList<float> list_float;
    LinkedList<string> list_string;

    cout << "inicio\n";
    LinkedList<int> list;
    for (int i = 0; i < 10000000000; i++)
    {
        list.append(i);
    }
 
    cout << "fim";
}
