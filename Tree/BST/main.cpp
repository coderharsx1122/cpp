/*
 BST -> creating BST
     ->Inserting node
     ->Travesing BST
*/
#include <iostream>

using namespace std;

// Node class to create tree node 
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // contructor
    Node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};


// function to insert data in the node and insert node in tree
Node* insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        root->right = NULL;
        root->left = NULL;
        return root;
    }
    if (data > root->data)
    {
      root->right =   insertIntoBST(root->right, data);
    }
    else
    {
       root->left= insertIntoBST(root->left, data);
    }
}


//function to traverse tree 
void treeTraverse(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    treeTraverse(root->left);
    treeTraverse(root->right);
    cout << root->data << endl;
}


// serach in bst
Node* Search(Node* root, int targetData){
    if(root==NULL) return NULL;
    if(targetData>root->data){
        return  Search( root->right,targetData);
    }
    if(targetData<root->data){
        return  Search( root->left,targetData);
    }
    return root;
}

int main()
{
    // create node
    Node* root = NULL;
    // insert nodes with data
    root = insertIntoBST(root, 12);
    root = insertIntoBST(root, 16);
    root = insertIntoBST(root, 1);
    root = insertIntoBST(root, 4);
    root = insertIntoBST(root, 7);

    // traverse tree
    treeTraverse(root);

    // search element in tree
    Node* ans = Search(root,1);


    return 0;
}