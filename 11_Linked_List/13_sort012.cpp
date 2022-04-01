// Sort 0,1,2 in linked list
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

// Approach 1: Count 0,1,2 and the change data accordingly

void sort012byCount(Node *head)
{
    // first we have to count
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            count0++;
            temp = temp->next;
        }
        else if (temp->data == 1)
        {
            count1++;
            temp = temp->next;
        }
        else
        {
            count2++;
            temp = temp->next;
        }

    }

    // Now we have store 0,1,2 count in their respective variable now we have to change data :
    Node *temp2 = head;

    while (count0--)
    {
        temp2->data = 0;
        temp2 = temp2->next;
    }
    while (count1--)
    {
        temp2->data = 1;
        temp2 = temp2->next;
    }
    while (count2--)
    {
        temp2->data = 2;
        temp2 = temp2->next;
    }
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


// Approach 2: Make three linked of each 0,1,2 seperately and merge them at the end

void insertAtTail(Node* &tail, Node* nodeToinsert)
{
    tail -> next = nodeToinsert;
    tail = nodeToinsert;
}

void sort012byLink(Node* &head)
{

    // creating dummy nodes for every list : 0s ,1s, 2s
    Node* zeroHead = new Node(-1);
    Node* tail0 = zeroHead;
    Node* oneHead = new Node(-1);
    Node* tail1 = oneHead;
    Node* twoHead = new Node(-1);
    Node* tail2 = twoHead;
    Node* temp = head;

    while(temp != NULL)
    {
        if(temp -> data == 0)
        {
            insertAtTail(tail0, temp);
        }
        else if(temp -> data == 1)
        {
            insertAtTail(tail1, temp);
        }
        else
        {
            insertAtTail(tail2, temp);
        }
        temp = temp -> next;
    }

    // Now merge that 3 list in way =>  0s-> 1s ->2s

    if(oneHead -> next != NULL)
    {
        tail0 -> next = oneHead -> next;
    }
    else
    {
        zeroHead -> next = twoHead -> next;
    }

    tail1 -> next = twoHead -> next;
    tail2 -> next = NULL;

    // set head
    head = zeroHead -> next;

    // delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

}




int main()
{
    Node *Node1 = new Node(0);
    Node *Node2 = new Node(2);
    Node *Node3 = new Node(1);
    Node *Node4 = new Node(0);
    Node *Node5 = new Node(1);
    Node *Node6 = new Node(0);
    Node *Node7 = new Node(2);
    Node *Node8 = new Node(0);

    // linking nodes
    Node1->next = Node2;
    Node2->next = Node3;
    Node3->next = Node4;
    Node4->next = Node5;
    Node5->next = Node6;
    Node6->next = Node7;
    Node7->next = Node8;
    Node8->next = NULL;

    Node *head = Node1;

    print(head);

    sort012byCount(head);



    print(head);

    return 0;
}