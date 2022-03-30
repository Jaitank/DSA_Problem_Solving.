/* Move last element to front of a given Linked List


Write a function that moves the last element to the front in a given Singly Linked List. For example, if the given Linked List is 1->2->3->4->5, then the function should change the list to 5->1->2->3->4.

*/

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

void print(Node *head)
{
    Node *temp = head;

    if(temp == NULL)
        return;

    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }

    cout << endl;
}


// replace first element with last element
void replaceFirstwithLast(Node* &head)
{
    Node* temp = head;
    while(temp -> next -> next != NULL)
    {
        temp = temp -> next;
    }

    temp -> next -> next = head -> next;
    Node* tail = temp -> next;
    temp -> next = head;
    head ->next = NULL;
    head = tail;
}



int main()
{
    // creating nodes
    Node *Node1 = new Node(3);
    Node *Node2 = new Node(4);
    Node *Node3 = new Node(5);
    Node *Node4 = new Node(6);
    Node *Node5 = new Node(9);
    Node *Node6 = new Node(13);

    // linking nodes
    Node1->next = Node2;
    Node2->next = Node3;
    Node3->next = Node4;
    Node4->next = Node5;
    Node5->next = Node6;
    Node6->next = NULL;

    Node *head = Node1;


    print(head);

    replaceFirstwithLast(head);

    print(head);


    return 0;
}