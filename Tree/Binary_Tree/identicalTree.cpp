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
// BUILD TREE
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

// is identical
bool isIdentical(Node *root1, Node *root2)
{

    if (root1 == NULL && root2 == NULL)
    {
        return true;
    };
    if(root1==NULL && root2 != NULL||root1!=NULL && root2 == NULL) return false;
    bool ansleft = false;
    bool ansright = false;
    if (root1->data == root2->data)
    {
        ansleft = isIdentical(root1->left, root2->left);
        ansright = isIdentical(root1->right, root2->right);
    }
    if (ansleft && ansright)
        return true;
    else
        return false;
}

int main()
{
    Node *root1 = NULL;
    Node *root2 = NULL;
    root1 = buildTree(root1);
    root2 = buildTree(root2);
    if(isIdentical(root1,root2)) cout<<"Identical trees"<<endl;
    else cout<<"Not identical trees"<<endl;
}
// 1 2 -1 -1 3 -1 3 -1 -1
// 1 2 -1 -1 3 -1 3 -1 -1
// 1 2 -1 -1 3 -1 4 -1 -1