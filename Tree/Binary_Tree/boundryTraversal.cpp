// print the nodes that are on the boundry of the tree
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// node
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
// BUILD TREE
Node *buildTree(Node *root)
{
    int data;
    cout << "Enter the data for node" << endl;
    cin >> data;
    root = new Node(data);
    if (data == -1)
        return NULL;
    // insert data for left node
    cout << "Insert data for left Node of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Insert data for right Node of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

// logic ->
/*
first print -> all left nodes from root node  ==> root->left->left->left------- excluded leaf node
then        -> print all leaf nodes
then        -> print all right nodes from root in revese order means bottom to root
 */
void leafNode(Node *root)
{
    if (root == NULL)
        return;

    leafNode(root->left);
    leafNode(root->right);

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << "  ";
    }
}
void leftNode(Node *root)
{
    if (root == NULL)
        return;

    if (root->left != NULL || root->right != NULL)
    {
        cout << root->data << " ";
    }
    leftNode(root->left ? root->left : root->right);
}
void rightNode(Node *root)
{
    if (root == NULL)
        return;
    rightNode(root->right ? root->right : root->left);
    if (root->left != NULL || root->right != NULL)
    {
        cout << root->data << " ";
    }
}
void boundryTraversal(Node *root)
{
    leftNode(root);
    leafNode(root);
    rightNode(root->right);
}
int main()
{
    Node *root = NULL;
    root = buildTree(root);
    boundryTraversal(root);
}
/*

1 2 4 8 -1 -1 9  12 -1 -1  13 -1 -1 5 -1 10 -1 -1 3 6 -1 -1 7  11 14 -1 -1 -1 -1

*/