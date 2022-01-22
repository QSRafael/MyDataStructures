#include "Stack.h"
#include <iostream>

int main()
{
    Stack<int> pilha;
    cout << "empty? ";
    pilha.isEmpty() ? cout << "true\n" : cout << "false\n";
    pilha.push(4);
    pilha.push(5);
    pilha.push(6);

    cout << "saida: " << pilha.pop() << "\n";
    cout << "saida: " << pilha.pop() << "\n";
    cout << "empty? ";
    pilha.isEmpty() ? cout << "true\n" : cout << "false\n";
    cout << "top: " << pilha.top() << "\n";
    cout << "top: " << pilha.top() << "\n";
    cout << "saida: " << pilha.pop() << "\n";
    cout << "empty? ";
    pilha.isEmpty() ? cout << "true\n" : cout << "false\n";


    Stack<float> pilha2;
    cout << "empty? ";
    pilha2.isEmpty() ? cout << "true\n" : cout << "false\n";
    pilha2.push(4.1);
    pilha2.push(5/2);
    pilha2.push(6.5);

    cout << "saida: " << pilha2.pop() << "\n";
    cout << "saida: " << pilha2.pop() << "\n";
    cout << "empty? ";
    pilha2.isEmpty() ? cout << "true\n" : cout << "false\n";
    cout << "top: " << pilha2.top() << "\n";
    cout << "top: " << pilha2.top() << "\n";
    cout << "saida: " << pilha2.pop() << "\n";
    cout << "empty? ";
    pilha2.isEmpty() ? cout << "true\n" : cout << "false\n";
}