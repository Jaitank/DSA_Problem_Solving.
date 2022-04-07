// Stack implementation using array ==>

#include <bits/stdc++.h>
using namespace std;

class Stack{

    // properties
    public:
    int size;
    int * arr;
    int top;

    // behaviour
    Stack(int size)
    {
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if(size - top > 1) // this means there is atleast 1 space to push an element
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "Stack overflow" << endl;
        }
    }

    void pop()
    {
        if(top >= 0) // check whether stack is empty or not,if not then pop
        {
            top--;
        }
        else
        {
            cout << "Stack Underflow" << endl;
        }
    }

    int peek()
    {
        if(top >=0) // if stack is not empty then return top element
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }


    bool isEmpty()
    {
        if(top == -1) // if top is at -1 means stack is empty;
            return true;
        else
            return false;
    }

};
int main()
{

    Stack st(5);

    st.push(22);
    st.push(78);
    st.push(2);

    cout << "Top element of stack is :" << st.peek() << endl;

    st.pop();

    cout << "Top element of stack is :" << st.peek() << endl;

    if(st.isEmpty())
    {
        cout << "Stack is Empty" << endl;
    }
    else{
        cout << "Stack is not Empty" << endl;
    }

    st.pop();
    st.pop();

    if(st.isEmpty())
    {
        cout << "Stack is Empty" << endl;
    }
    else{
        cout << "Stack is not Empty" << endl;
    }

    st.pop();

    st.peek();
    
    return 0;
}