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

int main()
{
    Node* root = NULL;
    root = insertIntoBST(root, 12);
    root = insertIntoBST(root, 16);
    root = insertIntoBST(root, 1);
    root = insertIntoBST(root, 4);
    root = insertIntoBST(root, 7);
    treeTraverse(root);
    return 0;
}