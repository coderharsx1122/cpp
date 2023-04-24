// zigzag traversal/spiral traversal
//---> right
//<---left
/*
      1   -->right  > 1
     / \
    2   3  <-- left > 3 2
   /     \
  4       5 -->right > 4 5
   final ans = 1 3 2 4 5

   input => 1 2 4 -1 -1 -1  3 -1 5 -1 -1
*/

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
    //    insert data for left node
    cout << "Insert data for left Node of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Insert data for right Node of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

// ZIG ZAG TRAVERSAL
vector<vector<int>> zzTraversal(Node *root)
{
    vector<vector<int>> result;
    if (root == NULL)
    {
        return result;
    }
    queue<Node *> q;
    q.push(root);
    bool toRight = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);
        for (int i = 0; i < size; i++)
        {
            Node *fnode = q.front();
            q.pop();
            // left to right || right to left
            int index = toRight ? i : (size - i - 1);
            ans[index] = fnode->data;
            if (fnode->left)
            {
                q.push(fnode->left);
            }
            if (fnode->right)
            {
                q.push(fnode->right);
            }
        }
       toRight = !toRight;
       result.push_back(ans);
    }
    return result;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    vector<vector<int>> ans = zzTraversal(root);
    for (auto i : ans)
    {
       for(auto j :i){
        cout<<j<<" ";
       }
    }
 
}