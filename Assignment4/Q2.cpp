/******************************
 *Name:Abhishek Raje
 *Roll No:bm22btech11002
 *Assignment 4:Advanced Trees
 Question 2
 ********************************/
#include <iostream>
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
 *Traversal of the Left side of Binary Tree
 ******************************/
void BoundryTraversalLeft(Node *Root)
{
    if (Root == NULL)
    {
        return;
    }
    BoundryTraversalLeft(Root->left);
    cout << Root->data << " ";
    //Time Complexity O(h)
    //where h is the height of the binary tree
    return;
}
/*****************************
 *Traversal of the Right side of Binary Tree
 ******************************/
void BoundryTraversalRight(Node *Root)
{
    if (Root == NULL)
    {
        return;
    }
    cout << Root->data << " ";
    BoundryTraversalRight(Root->right);
    return;
    
    //Time Complexity O(h)
    //where h is the height of the binary tree
}
/**************************************************
 *Function Including Both Left and Right Traversal
 *************************************************/
void BoundryTraversal(Node *Root)
{
    BoundryTraversalLeft(Root);
    BoundryTraversalRight(Root->right);
    //Time Complexity O(h)
    //where h is the height of the binary tre
}
int main()
{
    cout << "Algorithm to Print the Top View\nEnter data = -1 to Enter Node as NULL" << endl;
    Node *Root = BinaryTree();
    cout << "Top View :";
    BoundryTraversal(Root);
}
/*****************************
 *Time Complexity O(n)
 *Space Complexity O(n)
 ******************************/