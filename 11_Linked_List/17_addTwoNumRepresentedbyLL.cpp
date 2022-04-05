#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution
{
    private:
    Node* reverse(Node* head)
    {
        // if there is only one or none elements in linked list
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }
    Node * prev = NULL;
    Node * curr = head;
    Node * forward = NULL;
    while(curr != NULL)
    {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
    }
    public:
    
    
    void insertAtTail(struct Node* &head, struct Node* &tail, int val)
    {
        Node* temp = new Node(val);
        if(head == NULL)
        {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail -> next = temp;
            tail = temp;
        }
    }
    
    
    struct Node* add(struct Node* first, struct Node* second)
    {
        int carry = 0;
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        while(first != NULL || second != NULL || carry != 0)
        {
            int val1 = 0;
            if(first != NULL)
                val1 = first -> data;
            int val2 = 0;
            if(second != NULL)
                val2 = second -> data;
            int sum = carry + val1 + val2;
            
            int digit = sum % 10;
            
            // create node and add in ans linked list
            insertAtTail(ansHead, ansTail, digit);
            
            carry = sum/10;
            if(first!= NULL)
                first = first -> next;
            if(second != NULL)
                second = second -> next;
        }
        return ansHead;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // step1: reverse both linked list so we can add them: we know we perform add from last digits
        first = reverse(first);
        second = reverse(second);
        
        // Now add them
        Node* ans = add(first, second);
        
        // step3: reverse ans 
        ans = reverse(ans);
        
        return ans;
    }
};

int main()
{
    
    return 0;
}