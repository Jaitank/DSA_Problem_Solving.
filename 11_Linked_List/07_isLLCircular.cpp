// Checking LL is circular or not
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

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}


bool isCircularLL(Node* &head)
{
    // if linked list is empty then return true
    if(head == NULL)
    {
        return true;
    }

    Node* temp = head -> next;

    while(temp != NULL && temp != head)
    {
        temp = temp -> next;
    }

    if(temp == head)
    {
        return true;
    }

    return false;
}



int main()
{
    // creating nodes
    Node *Node1 = new Node(3);
    Node *Node2 = new Node(4);
    Node *Node3 = new Node(5);
    Node *Node4 = new Node(6);

    // linking nodes
    Node1->next = Node2;
    Node2->next = Node3;
    Node3->next = Node4;
    Node4->next= Node1;;
    // Node5->next= NULL;

    Node *tail = Node4;

    if(isCircularLL(tail))
    {
        cout << "Linked list is circular.";
    }
    else{
        cout << "Linked list is not circular";
    }
    
    return 0;
}