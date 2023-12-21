/******************************
 *Name:Abhishek Raje
 *Roll No:bm22btech11002
 *Assignment 4:Advanced Trees
 *Question 4
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
 *Function to Swap Nodes
 zz******************************/
Node *Swapping(Node *Root, int key)
{
    if (Root == NULL)
    {
        return NULL;
    }
    if (Root->data == key)
    {
        Node *temp = Root->left;
        Root->left = Root->right;
        Root->right = temp;
    }
    Swapping(Root->left, key);
    Swapping(Root->right, key);
    return Root;
    // Time Complexity O(h)
    // where h is the height of the tree
}
void preorder(Node *Root)
{
    if (Root == NULL)
    {
        return;
    }
    cout << Root->data << " ";
    preorder(Root->left);
    preorder(Root->right);
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
    // where n is the number of Nodes
}

int main()
{
    int key;
    cout << "Swapping the Left and Right Subtrees of the Binary Tree\nEnter data = -1 to Enter Node as NULL" << endl;

    Node *Root = BinaryTree();
    cout << "key :";
    cin >> key;
    cout << "preorder before : "<<endl;
    preorder(Root);
    Root = Swapping(Root, key);
    cout << "preorder after : "<<endl;
    preorder(Root);
    LevelOrderTraversal(Root);
}
/*****************************
 *Time Complexity O(n)
 *Space Complexity O(n)
 ******************************/