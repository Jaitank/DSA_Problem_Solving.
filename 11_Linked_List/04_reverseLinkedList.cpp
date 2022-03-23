// Reverse Linked List
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node * next;

    Node(int d)
    {
        this -> data = d;
        this -> next = NULL;
    }
};


void print(Node* &head)
{
    Node *temp = head; 
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp -> next;
    }

    cout << endl;
}

/*
Approach : Initialy linknedl list is like : { head -> Node1 -> Node2 -> Node3 -> Node4 -> NULL }
           Now we have to reverse this linked list , so for that we have to reverse thier links, means head is on Node4 ,
           Node4 pointed on Node3 like : { NULL <- Node1 <- Node2 <- Node3 <- Node4 <- head }
           For that we have to maintain 3 Pointers - prev, curr, and forward. Prev initially pointed NULL, curr on head, and forward pointed next node of curr, then we make curr pointed towards prev and shift prev to curr and curr to forward, and then again forward to next of curr. and we have to itertate this loop till curr shifts to NULL, then at that stage
           prev left on last node, so we return prev as head.
*/

// iteratively
Node * reverseLinkedList(Node *&head)
{
    // if there is only one or none elements in linked list
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }
    Node * prev = NULL;
    Node * curr = head;
    Node * forward = NULL;
    while(curr != NULL)
    {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

// recursively
Node * reverseLLusingRecursion(Node *&head, Node* prev = NULL)
{
    Node * curr = head;
    if(curr == NULL)
    {
        return prev;
    }
    head = head -> next;

    curr -> next = prev;

    prev = curr;

    return reverseLLusingRecursion(head, prev);

}
int main()
{
    // creating nodes
    Node * Node1 = new Node(3);
    Node * Node2 = new Node(4);
    Node * Node3 = new Node(5);
    Node * Node4 = new Node(6);

    // linking nodes
    Node1 -> next = Node2;
    Node2 -> next = Node3;
    Node3 -> next = Node4;
    Node4 -> next = NULL;

    Node * head = Node1;

    print(head);


    // Now we have to make a function to reverse this linked list

    head = reverseLinkedList(head);

    print(head);

    // again reverse it by using recursion funtion now

    head = reverseLLusingRecursion(head);

    print(head);

    
    return 0;
}