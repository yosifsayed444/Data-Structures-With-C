#include <iostream>
#include "linkedlist_with_C++.h"
using namespace std;
int main()
{
    LinkedList l1;
    l1.insertNodeintoTail(10);
    l1.insertNodeintoTail(10);
    l1.insertNodeintoTail(10);
    l1.insertNodeintoTail(10);
    l1.insertNodeintoTail(10);
    l1.insertHead(20);
    l1.insertHead(20);
    l1.insertHead(20);
    l1.insertHead(20);
    l1.insertNodeintoTail(30);
    l1.insertAtPosition(40, 2);
    l1.insertNodeintoTail(50);
    l1.insertNodeintoTail(50);
    l1.insertNodeintoTail(50);
    l1.insertNodeintoTail(50);
    l1.display();
    cout << "length of linked list is " << l1.length() << endl;
    cout << "sorted linked list is " << '\n';
    l1.SortLinkedList(l1.length(), l1);  
    l1.removeDublicates();
    cout << "reversed linked list is " << '\n';
    l1.reverseLinkedList();
}
