// BINARY TREE
// Find diameter of binary tree
#include <iostream>
#include <queue>
using namespace std;

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

// FUNCTION TO BUILD BINARY SEARCH TREE
Node *buildTree(Node *root)
{
    int data;
    cout << "Enter the data for node" << endl;
    cin >> data;
    root = new Node(data);
    if (data == -1)
        return NULL;

    //    insert data for left node
    cout << "Insert data for left Node of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Insert data for right Node of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

// int maxx
int max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}
// function to find height of tree
int height(Node *root)
{
    if (root == NULL)
        return 0;
    root->height = max(height(root->left), height(root->right)) + 1;
    return root->height;
}

// diameter of the tree
pair<int, int> diamerter(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> left;
    pair<int, int> right;
    left = diamerter(root->left);
    right = diamerter(root->right);
    int hleft = left.first ;
    int hright = right.first ;
    int cur = hleft + hright + 1;

    int ans = max(cur, max(left.second, right.second));
    pair<int, int> answer;
    answer.first = max(hleft+1,hright+1);
    answer.second = ans;
    return answer;
}

// inorder Traversal
void inOrderTrav(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrderTrav(root->left);
    cout << root->data << " ";
    inOrderTrav(root->right);
    return;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    cout << endl;
    int heigh = height(root);
    cout << "Height " << heigh;
    cout << endl;
    pair<int, int> d = diamerter(root);
    cout << "Diameter " << d.second << endl;
}
// 1 2 3 -1 -1 4 -1 -1 6 -1 -1