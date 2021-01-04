/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

//Create new node 
Node* CreateNode(int data){
    Node* newNode = new Node();
    if(!newNode){
        cout<<"Memory Error"<<endl;
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
}

//Inserting Node into empty branch in Binary Tree
Node* InsertNode(Node* root, int data){
    if(root == NULL){
        root = CreateNode(data);
        return root;
    }
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        if(temp->left != NULL)
            q.push(temp->left);
        else{
            temp->left = CreateNode(data);
            return root;
        }
        
        if(temp->right != NULL)
            q.push(temp->right);
        else{
            temp->right = CreateNode(data);
            return root;
        }
    }
}

//Traversal of the binary tree (recursion)
void inorder(Node* root){
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<' ';
    inorder(root->right);
}


int main()
{
    Node* root = CreateNode(10);
    root->left = CreateNode(11);
    root->left->left = CreateNode(7);
    root->right = CreateNode(9);
    root->right->left = CreateNode(15);
    root->right->right = CreateNode(8);
 
    cout << "Inorder traversal before insertion: ";
    inorder(root);
    cout << endl;
 
    int key = 12;
    root = InsertNode(root, key);
 
    cout << "Inorder traversal after insertion: ";
    inorder(root);
    cout << endl;
 
    return 0;
}