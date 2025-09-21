#include<bits/stdc++.h>
#include"DoublyLinkedList.h"
int main(){
    DoublyLinkedList dl;
    dl.insertAtTail(10);
    dl.insertAtTail(20);
    dl.insertAtTail(30);
    dl.insertAtTail(40);
    dl.insertAtTail(50);
    dl.insertAthead(5);
    dl.insertAthead(7);
    dl.insertAthead(9);
    dl.deleteAtPosition(4);
    dl.printList();
}