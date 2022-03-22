// Singly linked list creation, traversal, insertion and deletion operations.
// Learn destructor function used in deletion 

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

void deleteNode(int position, Node * & head, Node * & tail)
{
    if(position == 1)
    {
        // deleting starting or first node
        Node * temp = head;
        head = head -> next; // just point head to next node of first and then free the node

        // memory free for starting node
        temp -> next = NULL;
        delete temp;
    }
    else
    {

        
        // deleting middle or last node
        // here we have to maintain two pointer, one for node which we wanna delete, and for its just pvs node.
        Node *curr = head;
        Node *prev = NULL;
        
        int cnt = 1;
        while(cnt < position) // traverse curr pointer to the node which has to be delete, and prev to its previous one. 
        {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        if(curr -> next == NULL){
            prev -> next = NULL;
            tail = prev;
        }

        prev -> next = curr -> next; // now make prev node linked with next node of nodetodelete(which is pointed by curr).
        
        curr -> next = NULL;
        delete curr; // the free memory of that curr node

    }
}

void deleteNodebyValue(int value, Node *&head, Node *&tail)
{
    Node *curr = head;
    Node *prev = NULL;

    while (curr->next != NULL)
    {
        // if deletion has to be perfomed at starting or first node.
        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            curr = head;
            temp->next = NULL;
            delete temp; // delete the node
            // after deleting update curr and prev pointer to go further
            prev = curr;
            curr = curr ->next;
        }
        // if deletion is not for starting node then
        else
        {
            if (curr->data == value) 
            {
                Node *temp2 = curr;
                prev->next = curr->next;
                curr = curr->next;
                temp2->next = NULL;
                delete temp2;
            }
            else
            {   // shifting prev and curr
                prev = curr;
                curr = curr->next;
            }
        }
    }
    if (curr->data == value)
    {
        tail = prev;
        tail->next = NULL;
        delete curr;
    }
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
    insertAtHead(head,15);
    insertAtHead(head, 12);
    insertAtHead(head, 12);

    
    travereLinkedList(head);
    
    // insert new node at tail
    cout << "When inserting at tail : ";
    insertAtTail(tail, 8);
    insertAtTail(tail, 12);


    travereLinkedList(head);


    insertAtPosition(tail, head, 3, 11);

    cout << "When inserting at given position :";
    travereLinkedList(head);


    // checking head and tail of a linked list

    cout << "head :" << head -> data << endl;
    cout << "tail :" << tail -> data << endl;

    // deleteNode(6 ,head, tail);  // deletion wrt position

    deleteNodebyValue(12, head, tail); // deletion wrt to value

    cout << "After deletion :";
    travereLinkedList(head);

    cout << "head :" << head -> data << endl;
    cout << "tail :" << tail -> data << endl;



    return 0;
}