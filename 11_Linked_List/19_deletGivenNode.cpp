// question link: https://leetcode.com/problems/delete-node-in-a-linked-list/

/*
Write a function to delete a node in a singly-linked list. You will not be given access to the head of the list, instead you will be given access to the node to be deleted directly.

It is guaranteed that the node to be deleted is not a tail node in the list.


*/

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode *node)
{
    ListNode *nodeTodelete = node->next;

    // first save given nodeTodelete's data in given node value
    node->val = nodeTodelete->val;

    // then change links;
    node->next = nodeTodelete->next;

    // delete node
    delete nodeTodelete;
}

int main()
{

    return 0;
}