#include <bits/stdc++.h>
using namespace std;

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
    cout << "Enter data in root node :";
    int data;
    cin >> data;

    root = new Node(data);
    
    if(data == -1)
        return NULL;
    
    cout << "Enter data in left of " << data << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter data in right of " << data << endl;
    root -> right = buildTree(root -> right);


    return root;
}


int main()
{
    Node* root = NULL;

    //creating tree
    root = buildTree(root);
    return 0;
}