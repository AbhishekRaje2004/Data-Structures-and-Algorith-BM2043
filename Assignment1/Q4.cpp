/***************************************
 * Name:Abhishek Raje
 * Roll No:BM22BTECH11002
 * Assignment 1
 * Question 4
 ****************************************/
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int size;
    stack<int> s;
    cout << "Enter size of Array: " << endl;
    cin >> size;
    // initializing two arrays of size size
    int arr[size];
    int nextGreater[size];
    cout << "Enter Elements of the Array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    for (int i = size - 1; i >= 0; i--)
    {
        // for every element in the array it popes elements that are smaler than it in the stack
        while (!s.empty() && s.top() <= arr[i])
        {
            s.pop();
        }
        // if the stack is empty after the entire operation then  no greater element exist on the right side
        if (s.empty())
        {
            nextGreater[i] = -1;
        }
        // else the element on the top of stack is the next greater element
        else
        {
            nextGreater[i] = s.top();
        }
        // push element in the stack
        s.push(arr[i]);
        // time complexity O(n)
    }
    // printing  the array
    for (int i = 0; i < size; i++)
    {
        cout << nextGreater[i] << "\t";
    }

    return 0;
}
/*********************************************
 *Time Complexity of Whole Program O(n)
 *Space Complexity of the whole program is O(n)
 where n is the size of array
 **********************************************/