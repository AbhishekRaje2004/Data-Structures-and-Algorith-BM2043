/******************************
 *Name:Abhishek Raje
 *Roll No:bm22btech11002
 *Assignment 4:Advanced Trees
 Question 1
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

/**************************
 * Binary Tree Creation
 **************************/
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
/*******************************
 *Checking if List is sorted
 ********************************/
bool isSorted(vector<int> v)
{
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] < v[i - 1])
        {
            return false;
        }
    }
    return true;
    //Time Complexity O(n)
    //where n is the number of terms in the vector
}
/*******************************************
 *Function to check if Binary Tree is Sorted
 ********************************************/
bool isBinary(Node *Root, vector<int> &tree)
{
    if (Root == nullptr)
    {
        return true;
    }
    // inorder traversal of BST is sorted
    isBinary(Root->left, tree);
    tree.push_back(Root->data);
    isBinary(Root->right, tree);
    return isSorted(tree);

    //Time Complexity O(n)
    //where n is the number of nodes in the tree
}

int main()
{
    cout << "Algorithm to Check if Given Binary Tree is a BinarySearch Tree\nEnter data = -1 to Enter Node as NULL" << endl;
    Node *Root = BinaryTree();
    vector<int> tree;
    if (isBinary(Root, tree))
    {
        cout << "The tree is a binary search tree." << endl;
    }
    else
    {
        cout << "The tree is not a binary search tree." << endl;
    }

    return 0;
}

/************************
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 ************************/
