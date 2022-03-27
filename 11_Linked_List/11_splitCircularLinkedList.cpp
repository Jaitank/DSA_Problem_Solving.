// Split circular linked list in two equal parts and form two circular linked list from it.
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

    do
    {   cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int getLength(Node* head)
{
    Node *temp = head;
    int count = 0;
    if(temp == NULL)
        return 0;

    do
    {   count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}

// split linked list in two equal parts and return head of another linked list

Node* splitingLL(Node* &head)
{
    int len = getLength(head);
    int mid;

    if((len % 2) == 0)
    {
        mid = len / 2;
    }
    else
    {
        mid = (len / 2) + 1;
    }

    int count = 1;
    Node * temp = head;

    // shift temp pointer to mid of linked list
    while(count < mid)
    {
        temp = temp -> next;
        count++;
    }


    // make another head on next of temp, from where another linked list starts
    Node * head2 = temp -> next;

    
    // get tail of that second linked list  
    Node * tail = temp;

    // shift tails till the last of linked list
    while(count < len)
    {
        tail = tail -> next;
        count++;
    }

    // now we have 4 pointer: head , temp, head2 and tail, so,
    // 1). Linked list first part  = LL1: head ->> temp
    // 2). Linked list second part  = LL2: head2 ->> tail

    // split and make them circular
    temp -> next = head;
    tail -> next = head2;

    return head2;   

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
    Node6->next = Node1;

    Node *head = Node1;

    print(head);

    Node* head2 = splitingLL(head);

    cout << "Linked list first part :";
    print(head);
    cout << "Linked list second part: ";
    print(head2);


    return 0;
}