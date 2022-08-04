#include <bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* left;
    Node* right;

    //Constructor
    Node(int d)
    {
        this -> data = d;
        this -> right = NULL;
        this -> left = NULL;
    }

};

Node* insertIntoBST(Node* root, int d)
{
    // base case
    if(root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if(d > root -> data)
    {
        // insert into right of root
        root -> right = insertIntoBST(root -> right, d);
    }
    else{
        // insert into left
        root -> left = insertIntoBST(root -> left, d);
    }

    return root;
}


void takeInput(Node* &root)
{
    int data;
    cin >> data;

    while(data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}


int main()
{
    Node* root = NULL;
    takeInput(root);
    
    return 0;
}