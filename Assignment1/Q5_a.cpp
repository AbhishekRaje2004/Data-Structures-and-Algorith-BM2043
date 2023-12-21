/***************************************
 * Name:Abhishek Raje
 * Roll No:BM22BTECH11002
 * Assignment 1
 * Question 5
 * Queue implementation using stack
 ****************************************/
#include <iostream>
#include <stack>
using namespace std;
/***************************************
 * Printing Elements of a queue
 ****************************************/
void printStack(stack<int> s)
{
    cout << "Queue Currently" << endl;
    while (!s.empty())
    {
        cout << s.top() << "\t";
        s.pop();
    }
    cout << endl;
    // time complexity O(n)
    // where n is size of stack s
}

/***************************************
 * return front elemetn of the queue
 ****************************************/
int get_front(stack<int> s)
{
    if (s.empty())
    {
        return -1;
    }
    if (s.size() == 1)
    {
        return s.top();
    }
    s.pop();
    return get_front(s);
    // time complexity O(n)
    // where n is size of stack s
}

/***************************************
 * pushes element in the queue
 ****************************************/
void push(stack<int> &s, int element)
{
    s.push(element);
    // time complexity O(1)
}

/***************************************
 * checks if queue is empty
 ****************************************/
bool is_empty_queue(stack<int> &s)
{
    if (s.empty())
    {
        cout << "Queue is Empty." << endl;
        return true;
    }
    else
    {
        cout << "Queue is Not Empty." << endl;
        return false;
    }
    // time complexity O(1)
}

/***************************************
 * pops element of the queue
 ****************************************/
void pop_queue(stack<int> &s1, stack<int> &s2)
{
    if (s1.empty())
    {
        cout << "Queue is Empty." << endl;
    }
    else
    {
        while (!s1.empty())
        {
            int popped_element = s1.top();
            s2.push(popped_element);
            s1.pop();
        }
        int front_element = s2.top();
        s2.pop();
        while (!s2.empty())
        {
            int popped_element = s2.top();
            s1.push(popped_element);
            s2.pop();
        }
    }
}
// time complexity O(n)
// where n is size of stack

/***************************************
 * returns size of queue
 ****************************************/
int size_queue(stack<int> &s)
{
    return s.size();
    // time complexity O(1)
}
int main()
{
    int element;
    char ch;

    // Implement a queue using two stacks
    stack<int> s1;
    stack<int> s2;

    do
    {
        cout << "1.Front\n2.Push\n3.isEmpty\n4.Pop\n5.Size\n6.Exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case '1':
            cout << "The Value of Front Element is :" << get_front(s1) << endl;
            break;
        case '2':
            cout << "Enter Element to Push: ";
            cin >> element;
            push(s1, element);
            break;
        case '3':
            is_empty_queue(s1);
            break;
        case '4':
            pop_queue(s1, s2);
            break;
        case '5':
            cout << "Size of Queue :" << size_queue(s1) << endl;
            break;
        case '6':
            break;
        default:
            cout << "Enter a valid Input" << endl;
        }
        printStack(s1);
    } while (ch != '6');
    return 0;
}
/*********************************************
 *Time Complexity of Whole Program O(n)*number of operations by the user
 //where n is size of stack
 *Space Complexity of the whole program is O(n)
 //where n is  input size
 **********************************************/