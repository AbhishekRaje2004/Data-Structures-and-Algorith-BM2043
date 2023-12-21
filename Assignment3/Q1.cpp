/*****************************
 *Name: Abhishek Raje
 * Assignment Binaray Tree and Binary Search Tree
 *Q1
 ******************************/
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
        left = NULL;
        right = NULL;
    }
};
/*****************************
 *Binary Tree Creation
 ******************************/
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
    // where n are the number of nodes
}
/*****************************
 *Function to Calculate Height
 ******************************/
int CalcHeight(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int leftHeight = CalcHeight(node->left);
    int rightHeight = CalcHeight(node->right);
    return max(leftHeight, rightHeight) + 1;
    // Time Complexity O(n)
}
/*****************************
 *Function to Calculate Diameter
 ******************************/
int CalcDiameter(Node *Root)
{
    if (Root == NULL)
    {
        return 0;
    }

    int heightLeft = CalcHeight(Root->left);
    int heightRight = CalcHeight(Root->right);

    int diameterRoot = heightLeft + heightRight + 1;
    int diameterLeft = CalcDiameter(Root->left);
    int diameterRight = CalcDiameter(Root->right);

    return max(diameterRoot, max(diameterLeft, diameterRight));
    // Time Complexity O(n^2)
}

int main()
{
    cout << "Binary Tree Implementation\nEnter data = -1 to Enter Node as NULL" << endl;
    Node *Root = BinaryTree();
    cout << "Height of the Binary Tree: " << CalcHeight(Root) << endl;
    cout << "Diameter of the Binary Tree: " << CalcDiameter(Root) << endl;

    return 0;
}
/*****************************
 *Time Complexity O(n^2)
 *Space Complexity O(n)
 ******************************/