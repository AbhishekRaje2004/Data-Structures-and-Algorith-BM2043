/******************************
 *Name:Abhishek Raje
 *Roll No:bm22btech11002
 *Assignment 4:Advanced Trees
 Question 5
 ********************************/
#include <iostream>
#include <vector>
using namespace std;
/*******************************
 *Creating Node
 ********************************/
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
/************************
 * Binary Tree Creation
 ************************/
Node *BinaryTree()
{
    int data;
    cout << "Enter Data: ";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *Root = new Node(data);

    cout << "Enter Data in the Left of " << data << ": ";
    Root->left = BinaryTree();

    cout << "Enter Data in the Right of " << data << ": ";
    Root->right = BinaryTree();

    return Root;
    // Time Complexity O(n)
    // where n is the number of nodes
}
/********************************
 * Function to return MaxPathSum
 ********************************/
int maxPathSum(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }
    int leftPath = maxPathSum(root->left);
    int rightPath = maxPathSum(root->right);
    int maxChildPath = max(leftPath, rightPath);
    int ChildVsNode = max(maxChildPath, root->data);
    int SideAndNode = max(ChildVsNode, max(ChildVsNode, maxChildPath + root->data));
    int final = max(SideAndNode, leftPath + rightPath + root->data);
    return final;
    // Time Complexity O(n)
    // where n is the number of Nodes
}

int main()
{
    cout << "Finding the Maximum Path Sum of a Binary Tree\nEnter data = -1 to Enter Node as NULL" << endl;
    Node *Root = BinaryTree();
    cout << "Maximum Path Sum :" << maxPathSum(Root);
    return 0;
}

/************************
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 ************************/
