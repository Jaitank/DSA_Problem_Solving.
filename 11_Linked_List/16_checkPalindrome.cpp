/*
Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Example 1:
Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.


Example 2:
Input:
N = 4
value[] = {1,2,3,4}
Output: 0
Explanation: The given linked list
is 1 2 3 4 , which is not a palindrome
and Hence, the output is 0.
Your Task:
The task is to complete the function isPalindrome() which takes head as reference as the only parameter and returns true or false if linked list is palindrome or not respectively.

Expected Time Complexity: O(N)
Expected Auxialliary Space Usage: O(1)  (ie, you should not use the recursive stack space as well)

Constraints:
1 <= N <= 105

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

// Function to check whether the list is palindrome.

// Approach: Reverse the half of the linkedk list and then comapre both halves and if they are same then it is palindrome
// time complexity will be O(n) and space complexity will be O(1).

Node *reverseGiven(Node *temp)
{
    Node *curr = temp;
    Node *prev = NULL;
    Node *forward = NULL;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

Node *giveMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
bool isPalindrome(Node *head)
{
    if (head->next == NULL)
    {
        return head;
    }

    // Step1: find middle
    Node *midNode = giveMid(head);

    // Step2: Reverse linkedList after that middle
    Node *temp = midNode->next;
    midNode->next = reverseGiven(temp);

    // Step3: Now compare left part of mid with right part if same then palindrome
    Node *head1 = head;
    Node *head2 = midNode->next;

    while (head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    // Not necessary in this question but again make linkedlist as it we get initially
    temp = midNode->next;
    midNode->next = reverseGiven(temp);

    return true;
}
int main()
{

    return 0;
}