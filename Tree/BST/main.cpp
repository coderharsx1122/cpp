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
Node *insertIntoBST(Node *root, int data)
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
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }
}

// function to traverse tree
void treeTraverse(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    // inorder traversal
    treeTraverse(root->left);
    cout << root->data << " ";
    treeTraverse(root->right);
}

// search in bst
Node *Search(Node *root, int targetData)
{
    if (root == NULL)
        return NULL;
    if (targetData > root->data)
    {
        return Search(root->right, targetData);
    }
    if (targetData < root->data)
    {
        return Search(root->left, targetData);
    }
    return root;
}


Node *inorderPre(Node *root)
{
    root = root->left;
    if (root == NULL)
        return NULL;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

// function for deletion in BST
Node *Delete(Node *root, int targetdata)
{
    Node *pri;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    // search the node that is being to delete
    if (root->data < targetdata)
    {
        root->right = Delete(root->right, targetdata);
    }
    else if (root->data > targetdata)
    {
        root->left = Delete(root->left, targetdata);
    }

    // deletion
    else
    {
        pri = inorderPre(root);
        root->data = pri->data;
        root->left = Delete(root->left, pri->data);
    }
    return root;
}

int main()
{
    // create node
    Node *root = NULL;
    // insert nodes with data
    root = insertIntoBST(root, 12);
    root = insertIntoBST(root, 16);
    root = insertIntoBST(root, 1);
    root = insertIntoBST(root, 4);
    root = insertIntoBST(root, 7);

    // traverse tree
    treeTraverse(root);
    Delete(root, 1);
    cout << endl
         << "Root 1 deleted" << endl;
    treeTraverse(root);
    return 0;
}