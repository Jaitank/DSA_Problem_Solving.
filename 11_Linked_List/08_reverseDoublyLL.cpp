#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int d)
    {
        this -> data = d;
        this -> next = NULL;
        this -> prev = NULL;
    }

};

void print(Node *&head)
{
    Node *temp = head;
    if (temp == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// printing doubly linkedlist using prev field
void print2(Node *& head)
{

    Node * temp = head;
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    // by above loop our temp pointer is now on last node of linked list

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp -> prev;
    }
    cout << endl;

}

Node* ReversingDoublyLL(Node* &head, Node* pvs = NULL)
{
    // base condition
    if(head == NULL)
    {
        return pvs;
    }

    Node * curr = head;

    head = head -> next;
    curr -> next = pvs;
    curr -> prev = head;
    pvs = curr;
    return ReversingDoublyLL(head,pvs);
}

int main()
{
    // creating nodes
    Node * Node1 = new Node(10);
    Node * Node2 = new Node(15);
    Node * Node3 = new Node(2);
    Node * Node4 = new Node(18);

    // linking nodes
    Node1 -> next = Node2;

    Node2 -> prev = Node1;
    Node2 -> next = Node3;

    Node3 -> prev = Node2;
    Node3 -> next = Node4;

    Node4 -> prev = Node3;

    Node * head = Node1;

    print(head);

    // Now we have to reverse the linked list

    Node * newHead = ReversingDoublyLL(head);

    print(newHead);

    // printing reversily using prev field of doubly linked list
    print2(newHead);


    return 0;
}