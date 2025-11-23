#include <iostream>
#include"linkedStack2.h"
using namespace std;

class node
{
public:
    int value;
    node *next;
    node(int new_data)
    {
        value = new_data;
        next = nullptr;
    }
};

class LinkedList
{
public:
    node *head = NULL;
    // insert (in tail)
    void insertNodeintoTail(int data)
    {
        node *newNode = new node(data);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = nullptr;
        }
    }

    // insert in head
    void insertHead(int data)
    {
        node *newNode = new node(data);
        newNode->next = head;
        head = newNode;
    }

    // insert in position
    void insertAtPosition(int data, int pos)
    {
        node *newNode = new node(data);
        if (head == nullptr)
        {
            head = newNode;
        }
        if (pos == 0)
        {
            insertHead(data);
            return;
        }
        else
        {
            node *temp = head;
            for (int i = 0; i < pos - 1 && temp != nullptr; i++)
            {
                temp = temp->next;
            }
            if (!temp)
                return;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // delete FirstNode
    void deleteFirstNode()
    {
        if (!head)
            return;
        node *temp = head;
        head = head->next;
        cout << "Deleted " << temp->value << endl;
        delete temp;
    }

    // delete tail
    void deleteTail()
    {
        if (!head)
            return;
        if (!head->next)
        {
            delete head;
            head = NULL;
            return;
        }
        else
        {
            node *temp = head;
            node *prev = NULL;
            while (temp->next != NULL)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
            delete temp;
        }
    }

    // delete at position
    void deleteAtPosition(int pos)
    {
        if (!head)
            return;
        if (pos == 0)
        {
            deleteFirstNode();
            return;
        }
        else
        {
            node *temp = head;
            node *prev = NULL;
            for (int i = 0; i < pos - 1 && temp != NULL; i++)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            delete temp;
        }
    }

    // search
    bool search(int key)
    {
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->value == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // display
    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // length
    int length()
    {
        node *temp = head;
        int cnt = 0;
        while (temp != NULL)
        {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    // get occerance of specific index
    int getOcr(int data)
    {
        node *temp = head;
        int cnt = 0;
        while (temp != NULL)
        {
            if (temp->value == data)
            {
                cnt++;
            }
            temp = temp->next;
        }
        return cnt;
    }
    // get specific value at specific index   index--->val
    int &getNth(int index)
    {
        node *temp = head;
        for (int i = 0; i < index && temp != NULL; i++)
        {
            temp = temp->next;
        }
        return temp->value;
    }
    // sorting linked list
    void SortLinkedList(int size, LinkedList l1)
    {
        bool swapped;
        for (int i = 0; i < size - 1; i++)
        {
            swapped = false;
            for (int j = 0; j < size - i - 1; j++)
            {
                if (l1.getNth(j) > l1.getNth(j + 1))
                {
                    swap(l1.getNth(j), l1.getNth(j + 1));
                    swapped = true;
                }
            }

            if (!swapped)
                break;
        }
        l1.display();
    }
    // reverse linked list
    void reverseLinkedList()
    {
        Stack s;
        createStack(&s);
        node *temp = head;
        while (temp != NULL)
        {
            push(temp->value, &s);
            temp = temp->next;
        }
        while (!isstackempty(s))
        {
            cout << pop(&s) << " ";
        }
    }

    // get position(index) val--->index(1)
    int getPosition(int val)
    {
        node *temp = head;
        int pos = 1;
        while (temp != NULL)
        {
            if (temp->value == val)
                return pos;
            temp = temp->next;
            pos++;
        }
        return -1; // not found
    }

    void present(int val)
    {
        if (search(val))
        {
            int pos = getPosition(val);
            deleteAtPosition(pos);
            insertHead(val);
        }
        else
        {
            return;
        }
    }
    void removeDublicates()
    {
        SortLinkedList(length(), *this);
        node *temp = head;
        while (temp != NULL && temp->next != NULL)
        {
            if (temp->value == temp->next->value)
            {
                node *duplicate = temp->next;
                temp->next = duplicate->next;
                delete duplicate;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
};
