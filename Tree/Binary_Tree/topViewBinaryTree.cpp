#include <iostream>
#include <queue>
#include <map>
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

// top view of BST
vector<int> topView(Node *root)
{
    //    this map includes the verticle distance and currsponding node
    map<int, int> nodes;
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    int hdistance = 0;
    int level = 0;
    nodes[0] = root->data;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        Node *fnode = q.front().first;
        int hdist = q.front().second;
        q.pop();
        if (!nodes[hdist])
        {
            nodes[hdist] = fnode->data;
        }
        if (fnode->left)
        {
            q.push(make_pair(fnode->left, hdist - 1));
        }
        if (fnode->right)
        {
            q.push(make_pair(fnode->right, hdist + 1));
        }
    }
    for(auto i : nodes){
        ans.push_back(i.second);
    }
    return ans;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    vector<int> ans = topView(root);
    for(auto i : ans){
        cout<<i<<"  ";
    }
}

// 1 3 7 11 -1 -1  12  20  21 27 -1 -1 -1 -1 -1 8 -1 -1 4 9 -1 -1 10 16 -1 -1 -1
/*
           1
          / \
        3     4
       / \   / \
     7    8 9   10
    / \         /
  11   12     16
     /
    20
    /
  21
  /
27
ans ==> 27 11 7 3 1 4 10
*/