#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *kReverse(Node *head, int k)
{
    // base case
    if (head == NULL)
    {
        return NULL;
    }

    // reverse first k nodes
    Node *forward = NULL;
    Node *curr = head;
    Node *prev = NULL;
    int count = 0;

    while (curr != NULL && count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // rest recrusion will handle
    if (forward != NULL)
    {
        head->next = kReverse(forward, k);
    }

    // step 3: head is on prev
    return prev;
}

int main()
{

    return 0;
}