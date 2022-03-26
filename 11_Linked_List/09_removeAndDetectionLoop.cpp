 // We have to detect loop in linked list and remove it.
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d)
    {
        this -> data = d;
        this -> next = NULL;
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


bool detectLoop(Node* head)
{
    // we have to maintain a map for every node and when we have visited a node make its value true
    // so if we visits a node whose value is already true means, we have already visited on that node , means cycle is present

    if(head == NULL)
       return false;

    map<Node*, bool> visited;

    Node* temp = head;
    while(temp != NULL)
    {
        // cycle is present
        if(visited[temp] == true)
        {
            cout << "Loop is present on element :" << temp -> data << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp -> next;
    }

    return false;

    // this solution has time complexity of O(n) and space complexity is also of O(n)
    // so we have to create a solution by which we have to maintain space complexity in O(1):
    // for that we are going to use floyd algo for loop detection
}

// Floyd Loop detection algo:  Maintain two pointers fast and slow. Move fast 2 times in linked list,and move slow 1 times
// and if any where slow and fast collide with each other then there is a loop in linked list.

Node* floydDetectionLoop(Node *head)
{
    if(head == NULL)
        return NULL;

    Node * slow = head;
    Node * fast = head;

    while(slow != NULL && fast != NULL)
    {
        // move fast pointer 2 times
        fast = fast -> next;
        if(fast != NULL)
        {
            fast = fast -> next;
        }

        // move slow pointer 1 time
        slow = slow -> next;

        // when they both pointers meets then we can say there are loop and then that node, so we can check starting node of loop
        if(slow == fast)
        {
            return slow;
            // return true;
        }
            
    }
    // return false;
    return NULL;
}

// Now to get starting node we have to place the slow pointer to head again, and one intersection pointer where slow and fast meet
// then we have to traverse both on one-one node, with same speed, and when they meet, that will be the starting point of loop

Node * getStartingNode(Node * head)
{
    if (head == NULL)
        return NULL;
    
    Node* intersection = floydDetectionLoop(head);
    Node* slow = head;

    while(slow != intersection)
    {
        slow = slow -> next;
        intersection = intersection -> next;
    }

    // this loop ends when slow == intersection : and so this is starting node of loop so return slow or intersection

    return slow;
}

// get startingNode of loop and traverse till last node which is pointing that startinNode of loop and forms cycle
// then makes that nodes next as NULL and loop has been removed.
void removeLoop(Node* head)
{

    if (head == NULL)
        return;

    Node* startofLoop = getStartingNode(head);
    
    Node* temp = startofLoop;

    while(temp -> next != startofLoop)
    {
        temp = temp -> next;
    }

    temp -> next = NULL;
}


int main()
{
    // creating nodes
    Node * Node1 = new Node(3);
    Node * Node2 = new Node(4);
    Node * Node3 = new Node(5);
    Node * Node4 = new Node(9);
    Node * Node5 = new Node(13);
    Node * Node6 = new Node(89);

    // linking nodes
    Node1 -> next = Node2;
    Node2 -> next = Node3;
    Node3 -> next = Node4;
    Node4 -> next = Node5;
    Node5 -> next = Node6;
    Node6 -> next = Node3;

    Node * head = Node1;

    // we have to check does linked list have cycle in it, or loop in it.

    // if(detectLoop(head))
    // {
    //     cout << "Loop is there in linked list" << endl;
    // }
    // else
    // {
    //     cout << "There is no loop in linked list" << endl;
    // }

    if(floydDetectionLoop(head) != NULL)
    {
        cout << "Loop is there in linked list" << endl;
    }
    else
    {
        cout << "There is no loop in linked list" << endl;
    }

    cout << "Starting point of loop is : " << getStartingNode(head) -> data << endl;


    // removing loop from linked list

    removeLoop(head);
    print(head);



    return 0;
}