/*

A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

Example 1:

Input:
LinkedList: 4->5->6
Output: 457
Example 2:

Input:
LinkedList: 1->2->3
Output: 124
Your Task:
Your task is to complete the function addOne() which takes the head of the linked list as the only argument and returns the head of the modified linked list. The driver code prints the number.
Note: The head represents the left-most digit of the number.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 101000

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

// Solution : -

// function when we have to handle a case:  adding 1 in 9 : here we have to change in previous node also
Node *addIn9(Node *head, Node *index)
{
    // if index == head means there is only one node remaining for which we are going to check now so here we have to create
    //new node
    if (index == head)
    {
        // then we have to create a new Node
        Node *newNode = new Node(1);
        head->data = 0;
        newNode->next = head;
        head = newNode;
        return head;
    }

    // we will create temp and shift it tills the just previous node of index (tail node where data is 9):
    Node *temp = head;
    while (temp->next != index)
    {
        temp = temp->next;
    }

    // if temp also has data as 9 then we have to make recursive calls for it.
    if (temp->data == 9)
    {
        index->data = 0; // becuase index has 9
        temp->data = 0; // becuase temp also has 9
        return addIn9(head, temp);
    }
    // but if temp which is previous of node of index not have nine means now we have to just add 1 in its data and return
    else
    {
        index->data = 0;
        temp->data = temp->data + 1;
        return head;
    }
}

// Main function of Solution
Node *addOne(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // if temp -> data == 9 then we have to solve it by another function
    if (temp->data == 9)
    {
        return addIn9(head, temp);
    }
    // if not then we have to just add 1 into data
    else
    {
        temp->data = temp->data + 1;
        return head;
    }
}

int main()
{
    return 0;
}