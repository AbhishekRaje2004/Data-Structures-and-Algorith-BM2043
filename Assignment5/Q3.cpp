/**************************************************
 * Name:Abhishek Raje
 * Roll No:BM22BTECH11002
 * Assignment 5
 * Question 3
 ***************************************************/
#include <iostream>
#include <vector>
using namespace std;
/**************************************************
 * Creating node of Linked List
 ***************************************************/
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
/**************************************************
 * Creating class Linked List
 ***************************************************/
class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = NULL;
    }
    /**************************************************
     *Function to insert Element in Linked list
     ***************************************************/
    void Insert(int index, int data)
    {
        Node *InsertedNode = new Node(data);

        if (head == NULL || index == 0)
        {
            InsertedNode->next = head;
            head = InsertedNode;
            return;
        }
        else
        {
            Node *temp = head;
            Node *temp1 = head->next;
            int length = 1;
            for (int i = 0; i < index - 1 && temp1 != NULL; i++)
            {
                temp = temp->next;
                temp1 = temp1->next;
                length++;
            }
            if (index > length)
            {
                cout << "Invalid Index" << endl;
            }
            else
            {
                temp->next = InsertedNode;
                InsertedNode->next = temp1;
            }
        }
    }
    /**************************************************
     *Function to Search Element
     ***************************************************/
    void Search(int element)
    {
        Node *temp = head;
        int index = 0;
        while (temp != NULL)
        {
            if (temp->val == element)
            {
                cout << "Element Found at index " << index << endl;
                return;
            }
            temp = temp->next;
            index++;
        }
        cout << "Element Not Found " << endl;
        return;
    }
    /**************************************************
     *Function to Delete Element at Index
     ***************************************************/
    void DeleteNode(int index)
    {
        if (index == 0)
        {
            if (head != nullptr)
            {
                head = head->next;
                return;
            }
            else
            {
                cout << "List is empty" << endl;
                return;
            }
        }

        Node *temp = head;
        int length = 0;
        while (length != index - 1 && temp != nullptr)
        {
            temp = temp->next;
            length++;
        }
        if (index > length)
        {
            cout << "Invalid index" << endl;
            return;
        }
        (temp->next) = (temp->next->next);
        return;
    }
    /**************************************************
     *Function to return pointer at Head
     ***************************************************/
    void Head()
    {
        cout << "The pointer at Head: " << head << endl;
    }
    /**************************************************
     *Function to print Linked List
     ***************************************************/
    void PrintLinkedList()
    {
        cout << "List: ";
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->val << "  ";
            temp = temp->next;
        }
        cout << endl;
    }
};
/**************************************************
 *Function to merge 2 list in sorted way
 ***************************************************/
Node *mergeTwoLists(Node *l1, Node *l2)
{
    Node dummy(0);
    Node *current = &dummy;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            current->next = l1;
            l1 = l1->next;
        }
        else
        {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }
    current->next = l1 ? l1 : l2;
    return dummy.next;
    // Time Complexity:O(n)
}
/**************************************************
 * Function to merge k sorted linked lists
 ***************************************************/

Node *mergeKLists(vector<Node *> &lists)
{
    if (lists.empty())
    {
        return nullptr;
    }

    while (lists.size() > 1)
    {
        vector<Node *> new_lists;
        for (int i = 0; i < lists.size(); i += 2)
        {
            if (i + 1 < lists.size())
            {
                new_lists.push_back(mergeTwoLists(lists[i], lists[i + 1]));
            }
            else
            {
                new_lists.push_back(lists[i]);
            }
        }
        lists = new_lists;
    }

    return lists[0];
    // Time Complexity:O(n)
}

int main()
{
    LinkedList L;
    int size, ch, element, index;
    ch = 0;
    cout << "Implementation of Singly Linked List" << endl;

    vector<LinkedList> linkedLists;
    vector<Node *> lists;

    // Input k sorted lists
    cout << "Enter the number of sorted lists (k): ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        LinkedList list;
        int num, val;
        cout << "Enter the number of elements in list " << i + 1 << ": ";
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            cout << "Enter element  : ";
            cin >> val;
            list.Insert(j, val);
        }
        linkedLists.push_back(list);
        lists.push_back(list.head);
    }

    Node *mergedList = mergeKLists(lists);
    LinkedList mergedLinkedList;
    mergedLinkedList.head = mergedList;

    cout << "Merged Sorted List: ";
    mergedLinkedList.PrintLinkedList();

    return 0;
}
