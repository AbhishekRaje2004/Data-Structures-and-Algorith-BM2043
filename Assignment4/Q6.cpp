/******************************
 *Name:Abhishek Raje
 *Roll No:bm22btech11002
 *Assignment 4:Advanced Trees
 Question 6
 ********************************/
#include <iostream>
#include <vector>
using namespace std;
#include <sstream>
#include <string>

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
/************************
 * Function to Serialize Tree
 ************************/
string serialize(Node *root)
{
    if (root==NULL)
    {
        return "-1";
    }

    string left = serialize(root->left);
    string right = serialize(root->right);

    return to_string(root->data) + "," + left + "," + right;
}

int main()
{
    cout << "Algorithm to   Serialize the  Tree\nEnter data = -1 to Enter Node as NULL" << endl;
    Node *Root = BinaryTree();

    string serialized_tree = serialize(Root);
    cout << serialized_tree << endl; 

}

/************************
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 ************************/
