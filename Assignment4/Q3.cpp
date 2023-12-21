/******************************
 *Name:Abhishek Raje
 *Roll No:bm22btech11002
 *Assignment 4:Advanced Trees
 Question 3
 ********************************/
#include <iostream>
#include <queue>
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
 * Function to Create  Binary Tree
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
    //where n is the number of nodes
}
/***************************************
 *Function to Find Lowest Common Ancestor
 ***************************************/
Node *LowestCommonAncestor(Node *Root, int Node1_data, int Node2_data)
{
    if (Root == NULL)
    {
        return NULL;
    }
    if (Root->data == Node1_data || Root->data == Node2_data)
    {
        return Root;
    }
    Node *Left = LowestCommonAncestor(Root->left, Node1_data, Node2_data);
    Node *Right = LowestCommonAncestor(Root->right, Node1_data, Node2_data);
    if (Left != NULL && Right != NULL)
    {
        return Root;
    }
    else if (Left == NULL && Right != NULL)
    {
        return Right;
    }
    else if (Left != NULL && Right == NULL)
    {
        return Left;
    }
    else
    {
        return NULL;
    }
    // Time Complexity O(log(n))
    //where n is the number of nodes in the tree
}

int main()
{
    cout << "Lowest Common Ancestor of Nodes\nEnter data = -1 to Enter Node as NULL" << endl;
    int node1, node2;
    Node *Root = BinaryTree();
    cout << "Enter First Key :";
    cin >> node1;
    cout << "Enter Second Key :";
    cin >> node2;
    cout << "Lowest Common Ancestor :" << LowestCommonAncestor(Root, node1, node2)->data << endl;
}
/*****************************
 *Time Complexity O(n)
 *Space Complexity O(n)
 ******************************/