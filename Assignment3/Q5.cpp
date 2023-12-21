/*****************************
 *Name: Abhishek Raje
 * Assignment Binaray Tree and Binary Search Tree
 *Q5
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
 *Function to Implement BST
 ******************************/
Node *BinarySearchTree(Node *Root, int data)
{
    if (Root == NULL)
    {
        Root = new Node(data);
        return Root;
    }
    if (Root->data > data)
    {
        Root->left = BinarySearchTree(Root->left, data);
    }
    else
    {
        Root->right = BinarySearchTree(Root->right, data);
    }
    return Root;
    // Time Complexity O(logn)
}
/*****************************
 *Function to Inset Element
 ******************************/
void Insert(Node *&Root)
{
    cout << "Enter Element : ";
    int data;
    cin >> data;

    Root = BinarySearchTree(Root, data);
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
/*****************************
 *Function to count Nodes
 ******************************/
int countNodes(Node *Root)
{
    if (Root == NULL)
    {
        return 0;
    }
    int Total = countNodes(Root->left) + countNodes(Root->right) + 1;
    return Total;
    // Time Complexity O(n)
}
/*****************************
 *Function to find kth Smallest Node
 ******************************/
int kthSmallest(Node *root, int k)
{
    int leftCount = countNodes(root->left);

    if (k <= leftCount)
    {
        return kthSmallest(root->left, k);
    }
    else if (k == leftCount + 1)
    {
        return root->data;
    }
    else
    {
        return kthSmallest(root->right, k - leftCount - 1);
    }
    // Time Complexity O(logn)
}
/*****************************
 *Function to find kth Largest Node
 ******************************/
int kthLargest(Node *root, int k)
{
    int rightCount = countNodes(root->right);

    if (k <= rightCount)
    {
        return kthLargest(root->right, k);
    }
    else if (k == rightCount + 1)
    {
        return root->data;
    }
    else
    {
        return kthLargest(root->left, k - rightCount - 1);
    }
    // Time Complexity O(logn)
}
/*****************************
 *Function to minimum for a Node
 ******************************/
Node *findMin(Node *node)
{
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
    // Time Complexity O(n)
}
Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
    // Time Complexity O(logn)
}
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
    int ch;
    cout << "Implemenation of Binary Tree Functions" << endl;
    Node *Root = NULL;
    do
    {
        cout << "Enter 1 to Insert Node" << endl
             << "Enter 2 to find the kth Smallest Element" << endl
             << "Enter 3 to find the kth Largest Element" << endl
             << "Enter 4 to Find the Lowest Common Ancestor of two Nodes" << endl
             << "Enter 5 to Delete Node" << endl
             << "Enter 6 to Exit" << endl;
        cin >> ch;
        int k, n1, n2;
        switch (ch)
        {
        case 1:
            Insert(Root);
            break;
        case 2:
            cout << "Enter the Value of k :";
            cin >> k;
            cout << "kth Smallest Element :" << kthSmallest(Root, k) << endl;
            break;
        case 3:
            cout << "Enter the Value of k :";
            cin >> k;
            cout << "kth Largest Element :" << kthLargest(Root, k) << endl;
            break;
        case 4:
            cout << "Enter Node 1 :" << endl;
            cin >> n1;
            cout << "Enter Node 2 :" << endl;
            cin >> n2;
            cout << "Lowest Common Ancestor of " << n1 << " and " << n2 << " = " << LowestCommonAncestor(Root, n1, n2)->data << endl;
            break;
        case 5:
            cout << "Enter Element to Delete : ";
            cin >> k;
            Root = deleteNode(Root, k);
            break;
        case 6:
            cout << "Exiting " << endl;
        }
        cout << "Level Order Traversal" << endl;
        LevelOrderTraversal(Root);
    } while (ch != 6);
}