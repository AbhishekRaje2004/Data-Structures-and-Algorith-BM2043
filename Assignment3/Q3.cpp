/*****************************
 *Name: Abhishek Raje
 * Assignment Binaray Tree and Binary Search Tree
 *Q3
 ******************************/
#include <iostream>
#include <queue>
#include <stack>
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
 *Function to Create Binary Tree
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
}
/*****************************
 * Level Order Traversal
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
/*****************************
 * ZigZag Traversal
 ******************************/
void ZigZag(Node *root)
{
    if (!root)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);
    bool reverse = true;

    while (!q.empty())
    {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++)
        {
            Node *node = q.front();
            q.pop();

            if (reverse)
            {
                cout << node->data << " ";
            }
            else
            {
                cout << node->data << " ";
            }

            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }

        reverse = !reverse;
    }
    // Time Complexity O(n)
}
/*****************************
 * Depth First Search
 ******************************/
void preorder(Node *Root)
{
    if (Root == NULL)
    {
        return;
    }
    cout << Root->data << " ";
    preorder(Root->left);
    preorder(Root->right);
    // Time Complexity O()
}
int main()
{
    cout << "Traversal Algorithms Implementation\nEnter data = -1 to Enter Node as NULL" << endl;
    Node *Root = BinaryTree();
    cout << "Level Order Traversal" << endl;
    LevelOrderTraversal(Root);
    cout << "ZigZag Traversal" << endl;
    ZigZag(Root);
    cout << endl;
    cout << "Depth First Seach" << endl;
    preorder(Root);
}
/*****************************
 * Time Complexity O(n)
 * Space Complexity O(n)
 ******************************/