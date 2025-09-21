#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int value;
    node *next;
    node *prev;
    node(int new_data)
    {
        value = new_data;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList
{
public:
    node *head = NULL;

    void insertAthead(int data)
    {
        node *newNode = new node(data);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtTail(int data)
    {
        node *newNode = new node(data);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void insertAtposition(int data, int pos)
    {
        if (pos == 0)
        {
            insertAthead(data);
            return;
        }

        node *newNode = new node(data);
        node *temp = head;

        for (int i = 0; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL) 
        {
            cout << "Position out of range\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL) 
            temp->next->prev = newNode;

        temp->next = newNode;
    }

    void deleteHead()
    {
        if (head == NULL)
            return;

        node *temp = head;
        if (head->next == NULL) 
        {
            head = NULL;
        }
        else
        {
            head = head->next;
            head->prev = NULL;
        }
        delete temp;
    }

    void deleteTail()
    {
        if (head == NULL)
            return;

        node *temp = head;
        if (head->next == NULL) 
        {
            head = NULL;
            delete temp;
            return;
        }

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;
    }

    void deleteAtPosition(int pos)
    {
        if (head == NULL)
            return;

        if (pos == 0)
        {
            cout << "Deleted " << head->value << endl;
            deleteHead();
            return;
        }

        node *temp = head;
        for (int i = 0; i < pos && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL) 
        {
            cout << "Position out of range\n";
            return;
        }

        cout << "Deleted " << temp->value << endl;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        if (temp->prev != NULL)
            temp->prev->next = temp->next;

        delete temp;
    }

    void printList()
    {
        node *curr = head;
        while (curr != nullptr)
        {
            cout << curr->value;
            if (curr->next != nullptr)
            {
                cout << " <-> ";
            }
            curr = curr->next;
        }
        cout << endl;
    }
};
