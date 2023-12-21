/***************************************
 * Name:Abhishek Raje
 * Roll No:BM22BTECH11002
 * Assignment 1
 * Question 5
 * Stack implementation using queue
 ****************************************/
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
/***************************************
 * Printing Elements of a stack
 ****************************************/
void printStack(queue<int> q)
{
    cout << "Stack Currently" << endl;
    while (!q.empty())
    {
        cout << q.front() << "\t";
        q.pop();
    }
    cout << endl;
    // time complexity O(n)
    // where n is the size of queue
}
/***************************************
 * pushes element in the stack
 ****************************************/
void push_stack(queue<int> &q, int element)
{
    q.push(element);
    // time complexity O(1)
}
/***************************************
 * checks if stack is empty
 ****************************************/
bool is_empty_stack(queue<int> &q)
{
    if (q.empty())
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << "Stack is Not Empty" << endl;
    }
    // time complexity O(1)
}
/***************************************
 * pops element of the stack
 ****************************************/
void pop_stack(queue<int> &q1, queue<int> &q2)
{
    if (q1.empty())
    {
        cout << "Stack is empty." << endl;
    }
    else
    {
        while (!q1.empty())
        {
            int popped_element = q1.front();
            if (q1.size() != 1)
            {
                q2.push(popped_element);
            }
            q1.pop();
        }
        while (!q2.empty())
        {
            int popped_element = q2.front();
            q1.push(popped_element);
            q2.pop();
        }
    }
    // time complexity O(n)
    // where n is the size of queue
}
/***************************************
 * returns  element at top of the stack
 ****************************************/
int top_stack(queue<int> &q)
{
    return q.back();
    // time complexity O(1)
}
/***************************************
 * returns size of queue
 ****************************************/
int size_stack(queue<int> &q)
{
    return q.size();
    // time complexity O(1)
}
int main()
{ // stack implentation using queue
    int element;
    char ch;
    queue<int> q1;
    queue<int> q2;
    do
    {
        cout << "1.Push\n2.Pop\n3.isEmpty\n4.Peek\n5.Size\n6.Exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case '1':
            cout << "Enter Element to Push: ";
            cin >> element;
            push_stack(q1, element);
            break;

        case '2':
            pop_stack(q1, q2);
            break;
        case '3':
            is_empty_stack(q1);

            break;
        case '4':
            cout << "Element at Top :" << top_stack(q1) << endl;
            break;
        case '5':
            cout << "Size of Stack :" << size_stack(q1) << endl;
            break;
        case '6':
            break;
        default:
            cout << "Enter a valid Input" << endl;
        }
        printStack(q1);
    } while (ch != '6');
}
/*********************************************
 *Time Complexity of Whole Program O(n)
 //where n is the size of queue
 *Space Complexity of the whole program is O(n)
 //where n is the input size
 **********************************************/
