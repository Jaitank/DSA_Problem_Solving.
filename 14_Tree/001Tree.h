#include <bits/stdc++.h>

class Node{

    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }

};


Node* buildTree(Node* root)
{
    // data to enter in root
    int data;

    root = new Node(data);
    
    if(data == -1)
        return NULL;
    
    root -> left = buildTree(root -> left);
    root -> right = buildTree(root -> right);


    return root;
}

