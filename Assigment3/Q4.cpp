/*****************************
 *Name: Abhishek Raje
 * Assignment Binaray Tree and Binary Search Tree
 *Q4
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
    // Time Complexity
}
/*****************************
 *Level Order Traversal
 ******************************/
void LevelOrderTraversal(Node *Root)
{
    if (Root == NULL)
    {
        return;
    }

    queue<Node *> nodeQueue;
    nodeQueue.push(Root);
    nodeQueue.push(NULL);
    while (!nodeQueue.empty())
    {
        Node *current = nodeQueue.front();
        nodeQueue.pop();

        if (current == NULL)
        {
            cout << endl;
            if (!nodeQueue.empty())
            {
                nodeQueue.push(NULL);
            }
        }
        else
        {
            cout << current->data << " ";
            if (current->left)
            {
                nodeQueue.push(current->left);
            }

            if (current->right)
            {
                nodeQueue.push(current->right);
            }
        }
    }
    // Time Complexity O(n)
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
    // Time Complexity O(n)
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
    cout << "Level Order Traversal" << endl;
    LevelOrderTraversal(Root);
    cout << "Lowest Common Ancestor :" << LowestCommonAncestor(Root, node1, node2)->data << endl;
}
/*****************************
 *Time Complexity O(n)
 *Space Complexity O(n)
 ******************************/