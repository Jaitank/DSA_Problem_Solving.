// Removal of duplicates when linked list has values are sorted and unsorted.
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
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void removeDuplicates(Node *&head)
{

    // if empty elements
    if (head == NULL)
    {
        return;
    }

    // if there is only one element in list
    if (head->next == NULL)
    {
        return;
    }

    // becuase sorted list so maintaing two pointer and check values of two adjacent elements if values are same delete node,
    // if values are not same then shift both of them forward 1 time.
    Node *prev = head;
    Node *curr = head->next;

    while (curr != NULL)
    {

        if (curr->data == prev->data)
        {
            prev->next = curr->next;
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;
            delete temp;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
}


/* when data is unsorted : there can be multiple approaches for that:

1. Nested Loop, make pointer on each node and then check whole linked list for that, is there any duplicates
this will takes time complexity = O(n2) space complexity = O(1)

2. We can first sort using merge sort whose time complexit is O[n log n] and apply above code so its tc = O (nlogn) and sc = o(1)

3. Using map we can store each value and then check does it comes previously if yes then delete node

*/

// here we are going to code 3rd:  map approach

void  removalUnsorted(Node* head)
{
    if(head == NULL)
    {
        return;
    }

    map <int, Node*> duplicates;


    Node * curr = head -> next;
    Node* prev = head;
    duplicates[prev->data] = head;
    while(curr != NULL)
    {
        if(duplicates[curr->data] == NULL)
        {
            duplicates[curr->data] = curr;
            prev = curr;
            curr = curr -> next;
        }
        else{

            Node * NodetoDelete = curr;
            prev -> next = curr -> next;
            curr = curr -> next;
            NodetoDelete -> next = NULL;
            delete NodetoDelete;
        }
    }
}
int main()
{

    Node *Node1 = new Node(1);
    Node *Node2 = new Node(1);
    Node *Node3 = new Node(2);
    Node *Node4 = new Node(1);
    Node *Node5 = new Node(2);
    Node *Node6 = new Node(3);

    // linking them
    Node1->next = Node2;
    Node2->next = Node3;
    Node3->next = Node4;
    Node4->next = Node5;
    Node5->next = Node6;
    Node6->next = NULL;

    Node *head = Node1;

    cout << "Initially Linked list is :";

    print(head);

    // removeDuplicates(head);

    // when list is not sortedd
    removalUnsorted(head);

    cout << "Linked list after removal of duplicates :";

    print(head);

    return 0;
}