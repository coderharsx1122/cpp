// BINARY TREE
#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
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

// priorder Traversal
void priOrderTrav(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    inOrderTrav(root->left);
    inOrderTrav(root->right);
    return;
}

// postOrder Traversal
void postOrderTrav(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrderTrav(root->left);
    inOrderTrav(root->right);
    cout << root->data << " ";
    return;
}

// Level order traversal
// using queue
void blockLevelTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        if(temp!= NULL){ cout << temp->data << " ";}
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // inOrderTrav(root);
    cout << endl;
    blockLevelTraversal(root);
    cout<<endl;
    // inOrderTrav(root);
}

// 1 2 3 -1 -1 4 -1 -1 6 -1 -1