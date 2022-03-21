#include <bits/stdc++.h>
using namespace std;

// creating node for linked list
class Node{
    public:
    int data; // data field
    Node * next; // next field which store address of next node.

    // use of constructor to give data to node
    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }
};

// Insertion at starting of linked list
void insertAtHead(Node * & head, int data){

    // creating new node to insert at head
    Node * temp =  new Node(data);
    
    // then store address of node which is being pointed by head means first node
    temp -> next = head;

    // then make our new node as head, or point head pointer towards new node now.
    head = temp;
}

// Insert at the last of the linked list
void insertAtTail(Node * &tail, int data)
{
    // creating new node
    Node * temp =  new Node(data);

    // now store new node's address in tail's next field,
    tail -> next = temp;

    // and shift tail pointer to new node which is now last node.
    tail = tail -> next;
}


void insertAtPosition(Node* &tail, Node* &head, int position, int data)
{
    Node * temp = head; // making  a temp pointer to traverse
    int count = 1; // initialy we are on 1st node => so count = 1, in count we are storing the node no.

    // because we make count is 1 here so if we want to insert at 1st position so:
    if(position == 1)
    {
        insertAtHead(head, data);
        return;  // so that further below code cant run
    }

    while(count < position -1)  // we have to traverser till the previous node of position where we want to insert
    {                            
        temp = temp -> next;
        count++;
    }

    // here if we do insertion at last position then it will insert node but it do not update tail pointer
    // so we have to take care of it here.
    if(temp -> next == NULL)
    {
        insertAtTail(tail,data);
        return;  //so  that further below code cant run
    }

    // creating new node to insert
    Node * nodeToInsert = new Node(data);

    // now we have to insert this node like
    nodeToInsert -> next = temp -> next; // store the next node's address in new node->next 

    temp -> next = nodeToInsert; // then save our new node's address in that previous node which is being pointer by temp

}

// traversing linked list and printing linked list
void travereLinkedList(Node* &head)
{
    Node *temp = head; // for traversing we have to maintain a pointer temp which will jump from one node to next
                       // using next field of a node
    while(temp != NULL)    // traverse till last node
    {
        cout << temp->data << " ";
        temp = temp -> next;
    }

    cout << endl;
}
int main()
{
    // creating a node dynamically
    Node * node1 = new Node(10);

    // point head
    Node * head = node1;
    // point tail
    Node * tail = node1;

    travereLinkedList(head);

    // insert new node at head
    cout << "When inserting at head : ";
    insertAtHead(head, 12);
    insertAtHead(head, 15);

    
    travereLinkedList(head);
    
    // insert new node at tail
    cout << "When inserting at tail : ";
    insertAtTail(tail, 8);
    insertAtTail(tail, 6);


    travereLinkedList(head);


    insertAtPosition(tail, head, 3, 11);

    cout << "When inserting at given position :";
    travereLinkedList(head);


    // checking head and tail of a linked list

    cout << "head :" << head -> data << endl;
    cout << "tail :" << tail -> data << endl;


    return 0;
}