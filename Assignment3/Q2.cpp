/*****************************
 *Name: Abhishek Raje
 * Assignment Binaray Tree and Binary Search Tree
 *Q2
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
/**********************************
 *Function to return length of array
 **********************************/
int length(int arr[])
{
    int len = 0;
    while (arr[len] != -1)
    {
        len++;
    }
    return len;
    // Time Complexity O(n)
}
/**********************************************************
 *Function to Construct Tree from Preorder and Inorder Array
 ***********************************************************/
Node *ConstructTree(int Preorder[], int Inorder[], int &index, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int InorderLeft_count = 0;
    Node *Root = new Node(Preorder[index]);
    for (int i = start; i <= end; i++)
    {
        if (Inorder[i] != Preorder[index])
        {
            InorderLeft_count++;
        }
        else
        {
            break;
        }
    }
    index++;
    Root->left = ConstructTree(Preorder, Inorder, index, start, start + InorderLeft_count - 1);
    Root->right = ConstructTree(Preorder, Inorder, index, start + InorderLeft_count + 1, end);
    return Root;
    //Time Complexity O(n)
}
/*************************
 *Postorder Traversal
 ************************/
void postorder(Node *Root)
{
    if (Root == NULL)
    {
        return;
    }
    postorder(Root->left);
    postorder(Root->right);
    cout << Root->data << " ";
    //Time Complexity O(n)
}
/*************************
 *Preorder Traversal
 ************************/
void preorder(Node *Root)
{
    if (Root == NULL)
    {
        return;
    }
    cout << Root->data << " ";
    preorder(Root->left);
    preorder(Root->right);
    //Time Complexity O(n)
}
/*************************
 *Inorder Traversal
 ************************/
void inorder(Node *Root)
{
    if (Root == NULL)
    {
        return;
    }
    inorder(Root->left);
    cout << Root->data << " ";
    inorder(Root->right);
    //Time Complexity O(n)
}
/*************************
 *LevelOrder Traversal
 ************************/
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
    //Time Complexity O(n)
}

int main()
{   
    cout<<"Constructing Tree from Inorder and Preorder Traversal"<<endl;
    int Inorder[] = {5, 8, 10, 3, 14, 20, 22, 25, -1};  
    int Preorder[] = {20, 8, 5, 3, 10, 14, 22, 25, -1}; 
    cout<<"Inorder List :";
    for(int i=0;i<8;i++)
    {
        cout<<Inorder[i]<<" ";
    }
    cout<<endl;
       cout<<"Preorder List :";
    for(int i=0;i<8;i++)
    {
        cout<<Preorder[i]<<" ";
    }
    int index = 0;
    Node *Root = ConstructTree(Preorder, Inorder, index, 0, length(Inorder) - 1);
    LevelOrderTraversal(Root);
    cout<<"Preorder : ";
    preorder(Root);
    cout<<endl;
    cout<<"Postorder : ";
    postorder(Root);
    cout<<endl;
    cout<<"Inorder : ";
    postorder(Root);
    cout<<endl;
}
/*************************
 *Time Complexity O(n)
 Space Complexity O(n)
 ************************/
