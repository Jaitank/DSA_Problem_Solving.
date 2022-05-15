#include <bits/stdc++.h>
#include "001Tree.h"
using namespace std;

// Level order traversal - BFS (Breadth First Search)
void levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty())
    {
        Node* temp =  q.front();
        
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp -> data <<  " ";
            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }

        }
    }
}




// Inorder, PreOrder, and PostOrder traversals

void inOrder(Node* root)
{
    if(root == NULL)
        return;

    // Left -> Node -> right

    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);
}

void preOrder(Node* root)
{
    if(root == NULL)
        return;

    // NOde -> left -> right

    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}



int main()
{
    
    return 0;
}