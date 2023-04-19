#include <iostream>
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

// build tree
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
int max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}
// height
int height(Node *root)
{
    if (root == NULL)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    int height = max(left, right) + 1;
    return height;
}
// balance factor
int balaceFactor(int left, int right)
{
    int bf = left - right;
    return bf;
}
// find wheather the tree is balanced or not
pair<int, bool> isBalanced(Node *root)
{
    if (root == NULL)
    {

        pair<int, bool> p = make_pair(0, true);
        return p;
    }
    pair<int, bool> left = isBalanced(root->left);
    pair<int, bool> right = isBalanced(root->right);
    int height = max(left.first, right.first) + 1;
    int b = balaceFactor(left.first, right.first);
    pair<int, bool> ans;
    ans.first = height;
    if (b <= 1 && b >= -1 && left.second && right.second)
    {
        ans.second = true;
        return ans;
    }
    else
    {
        ans.second = false;
        return ans;
    }
}
// 1 3 5 -1 -1  -1 6 -1 7 -1 -1
int main()
{

    Node *root = NULL;
    root = buildTree(root);
}