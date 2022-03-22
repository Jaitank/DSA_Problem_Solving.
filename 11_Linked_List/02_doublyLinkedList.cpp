// Doubly linked list - creation, insertion, deletion etc:

#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
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

// function to calculate length of a linked list
int getLength(Node *&head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void insertAtHead(Node *&head, Node *&tail, int d)
{

    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        // create a new node
        Node *temp = new Node(d);

        // Now make new node next pointed towards head
        temp->next = head;

        // in doubly linked list prev also has to be maintained so make head's prev pointed towards new node
        head->prev = temp;

        // now when new node is head so shift head pointer to that new node (temp)
        head = temp;
    }
}

void insertAtTail(Node *&head, Node *&tail, int d)
{

    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        // creating new node
        Node *temp = new Node(d);

        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}

void insertAtPosition(int position, Node *&head, Node *&tail, int d)
{

    if (position > getLength(head) + 1)
    {
        cout << "Initially linked list is of length :" << getLength(head) << " So enter valid position" << endl;
        return;
    }
    int cnt = 1;
    Node *temp = head;

    if (position == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // create a new node
    Node *nodeToinsert = new Node(d);

    if (temp->next == NULL)
    {
        insertAtTail(head, tail, d);
        return;
    }

    nodeToinsert->prev = temp;
    nodeToinsert->next = temp->next;
    temp->next->prev = nodeToinsert;
    temp->next = nodeToinsert;
}

void deleteByPosition(Node *&head, Node *&tail, int position)
{
    int cnt = 1;
    Node *prvs = NULL;
    Node *curr = head;

    // deletion of starting or first node
    if(position == 1)
    {
        Node *temp = head;
        head = head->next;
        head -> prev = NULL;
        temp->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
    else
    {
        // traversing curr and prvs pointers to the position where deletion has to be perfomed
        while (cnt < position)
        {
            prvs = curr;
            curr = curr->next;
            cnt++;
        }

        // if cnt == length of linked list means we have to delete last node, and so have to maintain tail pointer
        if (cnt == getLength(head))
        {
            tail = prvs;
            prvs -> next = NULL;
            curr->prev = NULL;
            curr->next = NULL;
            delete curr;
        }
        else
        {
            // position where we have to perform deletion is here-
            prvs->next = curr->next;
            curr->next->prev = prvs;
            curr->prev = NULL;
            curr->next = NULL;
            delete curr;
        }
    }
}
int main()
{
    // if there is no node initially
    // Node *node1 = new Node(10);
    Node *head = NULL;
    Node *tail = NULL;

    print(head);

    cout << "Length: " << getLength(head) << endl;

    insertAtHead(head, tail, 11);

    print(head);

    cout << "Length: " << getLength(head) << endl;

    insertAtTail(head, tail, 9);

    print(head);

    cout << "Length: " << getLength(head) << endl;

    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;

    insertAtPosition(3, head, tail, 5);
    insertAtPosition(4, head, tail, 6);
    insertAtPosition(1, head, tail, 20);

    print(head);

    cout << "Length: " << getLength(head) << endl;

    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;

    // insertAtPosition(10, head, tail, 20);

    deleteByPosition(head, tail, 1);
    deleteByPosition(head, tail, 4);

    cout << "Linked list after deletion :";
    print(head);

    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;


    return 0;
}