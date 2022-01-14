#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList list;
    list.print();
    list.isPalindrome()?cout << "palindrome":cout << "noPalindrome";
    return 0;
}
