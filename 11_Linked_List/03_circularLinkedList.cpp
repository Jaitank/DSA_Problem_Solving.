// Circular linked list:  here we do not have to worry about starting and ending becuase this is circular
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void insertionAfterValue(Node *&tail, int value, int d)
{
    // when list is empty
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        tail->next = newNode;
    }
    else
    {
        // non empty list
        Node *curr = tail;
        while (curr->data != value)
        {
            curr = curr->next;
        }
        // after above loop value is matched with curr data, so now next to it we have to insert a node.
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node *tail)
{
    if(tail == NULL)
    {
        cout << "List is empty";
        return;
    }
    Node *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

void deletebyElement(Node *&tail, int element)
{
    Node *prev = tail;
    Node *curr = tail->next;

    // if there is only one element in list
    if(curr == prev)
    {
        tail = NULL;
        delete prev;
        return;
    }
    // if more than one elements are present
    while (curr->data != element && curr != tail) // if element is not found then in full traversel means till curr != tail, stop
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr->data == element && curr == tail)   // if element is founded where tail is pointed then we have to take care of tail
    {
        prev->next = curr->next;
        tail = curr -> next;
        curr->next = NULL;
        delete curr;
    }
    else if (curr->data == element)
    {
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    Node *tail = NULL;

    insertionAfterValue(tail, 5, 3);
    insertionAfterValue(tail, 3, 7);

    print(tail);

    insertionAfterValue(tail, 7, 8);
    print(tail);

    insertionAfterValue(tail, 8, 9);
    print(tail);

    insertionAfterValue(tail, 3, 4);
    print(tail);

    deletebyElement(tail, 3);
    deletebyElement(tail, 4);
    deletebyElement(tail, 7);
    deletebyElement(tail, 8);
    print(tail);

    deletebyElement(tail,9);
    print(tail);

    return 0;
}