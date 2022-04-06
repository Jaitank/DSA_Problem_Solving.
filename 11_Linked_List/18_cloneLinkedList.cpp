/*

Lecture 52: revise again

You are given a special linked list with N nodes where each node has a next pointer pointing to its next node. You are also given M random pointers, where you will be given M number of pairs denoting two nodes a and b  i.e. a->arb = b.

Construct a copy of the given list. The copy should consist of exactly N new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

ArbitLinked List1

Example 1:

Input:
N = 4, M = 2
value = {1,2,3,4}
pairs = {{1,2},{2,4}}
Output: 1
Explanation: In this test case, there
are 4 nodes in linked list.  Among these
4 nodes,  2 nodes have arbitrary pointer
set, rest two nodes have arbitrary pointer
as NULL. Second line tells us the value
of four nodes. The third line gives the
information about arbitrary pointers.
The first node arbitrary pointer is set to
node 2.  The second node arbitrary pointer
is set to node 4.


Example 2:

Input:
N = 4, M = 2
value[] = {1,3,5,9}
pairs[] = {{1,1},{3,4}}
Output: 1
Explanation: In the given testcase ,
applying the method as stated in the
above example, the output will be 1.

Your Task:
The task is to complete the function copyList() which takes one argument the head of the linked list to be cloned and should return the head of the cloned linked list.

NOTE : 
1. If there is any node whose arbitrary pointer is not given then it's by default NULL. 
2. Your solution return an output 1 if your clone linked list is correct, else it returns 0.

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(1)

Constraints:
1 <= N <= 100
1 <= M <= N
1 <= a, b <= 100

*/

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node* arb;

    Node(int x)
    {
        data = x;
        next = NULL;
        arb = NULL; // random pointer
    }
};

// This is the solution in which we will going to use mapping for set random pointers in clone linked list
// so our time complexity - O(n) and space complexity - O(n)

class Solution
{
    private:
    void insertAtTail(Node* &head, Node* &tail, int val)
    {
        Node* newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        else
        {
            tail -> next = newNode;
            tail = newNode;
        }
    }
    public:
    Node *copyList(Node *head)
    {
        // step1 : create a clone list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        
        while(temp != NULL)
        {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp -> next;
        }
        
        // Step2: map clone linked list with original one
        unordered_map<Node*, Node*> originalToClone;
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL)
        {
            originalToClone[originalNode] = cloneNode;
            
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
            
        }
        // mapping saved till now
        
        // Step3: Now we have to arrange random pointer using that mapping
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode != NULL)
        {
            cloneNode -> arb = originalToClone[originalNode -> arb];
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }
        
        
        return cloneHead; 
        
    }

};


// Above solution we know takes time and space both complexities as O(n), but we have to optimise it,
// in a way so that space complexity can be O(1).

class Solution2
{
    private:
    void insertAtTail(Node* &head, Node* &tail, int val)
    {
        Node* newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        else
        {
            tail -> next = newNode;
            tail = newNode;
        }
    }
    public:
    Node *copyList(Node *head)
    {
        // step1 : create a clone list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        
        while(temp != NULL)
        {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp -> next;
        }
        
        // Step2: add clone node in b/w original list nodes
        // like original = 1 -> 2 -> 3 ->NULL
        //      clone    = 1 -> 2 -> 3 -> NULL 
        // new list  =  1 -> 1 -> 2 -> 2 -> 3 -> 3 -> NULL
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL)
        {
            Node* forward = originalNode -> next;
            originalNode -> next = cloneNode;
            originalNode = forward;
            
            forward = cloneNode -> next;
            cloneNode -> next = originalNode;
            cloneNode = forward;
        }
        
        
        
        // Step3: random pointer copy
        temp = head;
        
        while(temp != NULL)
        {
            if(temp -> next != NULL)
            {
                if(temp -> arb != NULL) // if anyNode has arb or random pointer null then nothing to do
                {
                    temp -> next -> arb = temp -> arb -> next;
                }
            }
            
            temp = temp -> next -> next;
            
        }
        
        // step4: revert changes done in step2
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode != NULL)
        {
            originalNode -> next = cloneNode ->next;
            originalNode = originalNode -> next;
            
            if(originalNode != NULL)// we have to check this again becuase we have shifted original in above line, so there can be chance that original 
            // now shifts to NULL and if yes then in forward we cant use originalNode -> next becuase it will
            // become null -> next and code phat jayega.
            {
                cloneNode -> next = originalNode -> next;
            }
            
            cloneNode = cloneNode -> next;
             
        }
        
        // step5: return ans
        return cloneHead;
        
    }

};


int main()
{
    
    return 0;
}