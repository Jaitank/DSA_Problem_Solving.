// Find mid of linked list
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

/* We have to find mid of the linked list so for that we have two approach
  1. (Length/2) and find mid accordingly, length is even or odd.
  2. traverse two pointer i.e fast and slow. fast traverse two nodes at a iteration and slow traverse one node,
     so when fast one is on the end, then obviously slow pointer is somewhere on mid.
*/

int getLength(Node *&head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

Node *MidofLL1(Node *&head)
{
    int length = getLength(head);
    // in case of even there can be two mid - (length/2, length/2 + 1); // suppose you have to consider only  length / 2 + 1; as mid
    int mid = length / 2 + 1;
    Node *temp = head;
    int cnt = 1;
    while (cnt < mid)
    {
        temp = temp->next;
        cnt++;
    }
    return temp;
}

Node *MidofLL2(Node* &head)
{
    Node* slow = head;
    Node * fast = head -> next;

    while(fast->next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next;
        if(fast -> next != NULL)
        {
            fast = fast -> next;
        }
    }
    return slow;
}

int main()
{
    // creating nodes
    Node *Node1 = new Node(3);
    Node *Node2 = new Node(4);
    Node *Node3 = new Node(5);
    Node *Node4 = new Node(6);
    Node *Node5 = new Node(9);

    // linking nodes
    Node1->next = Node2;
    Node2->next = Node3;
    Node3->next = Node4;
    Node4->next= Node5;
    Node5->next= NULL;

    Node *head = Node1;

    cout << "Length of Linked list is :" << getLength(head) << endl;

    cout << "Mid of Linked list is :" << (MidofLL1(head)) -> data << endl;
    cout << "Mid of Linked list is :" << (MidofLL2(head)) -> data << endl;

    return 0;
}