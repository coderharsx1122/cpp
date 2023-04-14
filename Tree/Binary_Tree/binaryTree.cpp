#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right= NULL;
    }
};

// FUNCTION TO BUILD BINARY SEARCH TREE
Node* buildTree(Node* root){
    int data;
    cout<<"Enter the data for node"<<endl;
    cin>>data;
    if(data == -1) return NULL;
    root = new Node(data);


//    insert data for left node
   cout<<"Insert data for left Node of"<<data<<endl;
   root->left = buildTree(root->left);
   cout<<"Insert data for right Node of"<<data<<endl;
   root->left = buildTree(root->right);

   return root;
}

void inOrderTrav(Node* root){
    inOrderTrav(root->left);
    cout<<root->data<<endl;
    inOrderTrav(root->right);
}

int main(){
   Node* root = NULL;
   root = buildTree(root);
   inOrderTrav(root);
}