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

Node* invertTree(Node* root){
    if(root==NULL) return root;
    Node* rootLeft = root->left;
    Node* rootRight = root->right;
    root->right= rootLeft;
    root->left=rootRight ;
    root->left = invertTree(root->left);
    root->right = invertTree(root->right);

}

int main(){
    Node* root = NULL;
    root= buildTree(root);
    root = invertTree(root);
}