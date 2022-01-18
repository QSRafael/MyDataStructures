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

    for (int i = 0; i < 10; i++)
    {
        list_int.append(i);            // adicionando no fim
        list_int.push(i * i / 2);      // adicionando na frente
        list_float.append(i * 3.1415); // multiplos de pi
    }

    cout << "\n\n";

    list_string.append("ola!");
    list_string.append("Me chamo Rafael");
    list_string.append("e esse eh um teste de uma lista ligada");

    list_string.print(); // printando a mensangem inicial

    cout << "\nPara adicionar elementos use push() ou append()\n\n";
    list_int.print();

    cout << "Para deletar use deleteValue() ou deletePosition()\n";
    cout << "deletando os elementos 1, 2 e 3:\n";
    list_int.deleteValue(1);
    list_int.deleteValue(2);
    list_int.deleteValue(3);
    list_int.print();

    cout << "\nAlias, use print() para imprimir a lista\n";

    cout << "\nsize() retorna o tamanho da lista:\n";
    cout << "tamanho da list_int: " << list_int.size() << "\n";

    cout << "\ninList() verifica se um elemento está na lista e count() diz quantas vezes ele aparece :\n ";
    cout << "2 esta em list_float? " << list_float.inList(2) << "\n";

    cout << "\nreverseList() cria uma nova lista na ordem inversa e reverse() reverte a lista inplace\n";
    list_float.print();
    list_float.reverse();
    cout << "list_float apos o reverse():\n";
    list_float.print();

    cout << "\nswap troca elementos ou nodes de lugares:\n";
    cout << "trocando o 2 e o 3 de lugar em list_int:";
    list_int.swap(2,3);
    cout << "trocando o 1 com o 2 elemendo de lugar na lista de introducao:\n";
    list_string.swap(list_string(0),list_string(2));

    cout << "\nsort() ordena listas numericas:\n";
    list_int.sort();
    list_int.print();

    cout << "\nremoveDuplicates(), segregateEvenOdd() e isPalindrome() sao autoexplicativas\n";

    cout << "\npor ultimo, createLoopInPosition() e loopSize() sao expirimentais. Nao mexa neles\n";
    
    cout << "\nObrigado!\n";
}
