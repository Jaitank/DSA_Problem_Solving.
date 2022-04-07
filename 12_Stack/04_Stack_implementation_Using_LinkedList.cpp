// Implementing Stack Using LinkedList

#include <bits/stdc++.h>
using namespace std;

class Stack_Node{
    public:
    int data;
    Stack_Node* next;
    Stack_Node * top = NULL;
    Stack_Node* head = NULL;

    void push(int val)
    {
        
        if(top == NULL)
        {
            Stack_Node * newNode = new Stack_Node;
            newNode -> data = val;
            newNode -> next = NULL; 
            top = newNode;
            head = newNode;
            
        }
        else{
            Stack_Node* newNode = new Stack_Node;
            newNode -> data = val;
            newNode -> next = NULL;
            top -> next = newNode;
            top = newNode;
        }
    }

    void pop()
    {
        if(top == NULL)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        if(top == head)
        {
            Stack_Node* deleteNode = top;
            head = NULL;
            top = NULL;
            free(deleteNode);
            return;
            
        }
        Stack_Node* temp = head;
        while(temp -> next != top)
        {
            temp = temp -> next;
        }

        Stack_Node* deleteNode = top;
        top = temp;
        top -> next = NULL;
        free(deleteNode);
    }

    void print()
    {
        Stack_Node* temp = head;
        while(temp != NULL)
        {
            cout << temp -> data << endl;
            temp = temp -> next;
        }
    }

    int peek()
    {
        if(top == NULL)
        {
            cout << "list is empty" << endl;
        }
        if(top != NULL)
        {
            return top -> data;
        }  
    }

    bool isEmpty()
    {
        if(top == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};


int main()
{
    Stack_Node st;
    st.push(23);
    st.push(12);
    st.push(532);

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    if(st.isEmpty())
    {
        cout << "list is empty"<< endl;
    }
    else
    {
        cout << "list is not empty" << endl;
    }


    st.pop();  

    st.push(222);   

    cout << st.peek() << endl;


    st.push(2352);

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    st.pop();
    st.pop();


    return 0;
}