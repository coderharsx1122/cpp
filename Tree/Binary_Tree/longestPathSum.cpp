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

int max(int x,int y){
    if(x>y) return x;
    else return y;
}

int height(Node* root){
    if(root==NULL) return 0;
    int left = height(root->left);
    int right = height(root->right);
    int h= max(left,right) + 1;
    return h;
}

int longestPathSum(Node* root){
    int sum = root->data;
    int left = height(root->left);
    int right = height(root->right);
    if(left>right){
        sum+= longestPathSum(root->left);
    }
    if(left<right){
        sum+= longestPathSum(root->right);
    }
    return sum;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    int sum = longestPathSum(root);
    cout<<"Sum of longest path is "<<sum<<endl;
}