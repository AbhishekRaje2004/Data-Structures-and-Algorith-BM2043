/***************************************
 * Name:Abhishek Raje
 * Roll No:BM22BTECH11002
 * Assignment 1
 * Question 1
 ****************************************/
#include <iostream>
using namespace std;
/**************************************************************
 * Creating a Class Stack containing the properties and methods
 **************************************************************/
class Stack
{
public:
    // defineing the properties of stack
    int top;
    int *arr;
    int size;
    // creating the constructor defining the initial properties of stack
    Stack(int size)
    {
        this->size = size;
        this->top = -1;
        this->arr = new int[size];
    }

    /******************************************************
     * returns the position of top pointer of the stack
     *******************************************************/

    int get_top()
    {
        // returns top pointer of the current object
        return this->top;
        // time complexity O(1)
    }
    /*****************************************
     * pushes the element in the stack
     ******************************************/
    void push(int element)
    {
        if (is_full())
        {
            // returns the function in case the stack is full
            return;
        }
        // updates the  value of top and inserts the element in the stack
        this->top++;
        this->arr[this->top] = element;
        // time complexity O(1)
    }
    /*****************************************
     * returns arr[top]
     ******************************************/
    int peek()
    {
        // returns the element at the top pointer at the stack
        return this->arr[this->top];
        // time complexity O(1)
    }
    /************************************************************
     * returns true  if the the stack is empty else returns false
     ***************************************************************/

    bool is_empty()
    {
        if (this->top == -1)
        {
            cout << "Stack Underflow" << endl;
            return true;
        }
        cout << "Stack is not Empty" << endl;
        return false;
        // time complexity O(1)
    }
    /*****************************************
     * pops the element present at the top pointer
     ******************************************/

    int pop()
    {
        if (is_empty())
        {
            // returns -1 if the stack is empty i.e stack cannot be stacked
            return -1;
        }
        // element at the top pointer
        int poped_element = this->arr[this->top];
        // updating value of stack
        this->top--;
        return poped_element;
        // time complexity O(1)
    }
    /*****************************************
     * returns the size of the stack
     ******************************************/
    int get_size()
    {
        return this->top + 1;
        // time complexity O(1)
    }
    /******************************************************
     * returns true if the stack isd full else returns false
     ********************************************************/
    bool is_full()
    {
        if (this->top == this->size - 1)
        {
            cout << "Stack Overflow" << endl;
            return true;
        }
        return false;
        // time complexity O(1)
    }
};
/*****************************************
 * printing the stack
 ******************************************/
void printStack(Stack s)
{
    cout << "Stack Currently:" << endl;
    for (int i = s.top; i >= 0; i--)
    {
        cout << s.arr[i] << "\n";
    }
    cout << endl;
    // time complexity O(n)
    // where n is the current size of stack
}
int main()
{
    int size, ch, element;
    ch = 0;
    // prompting the user to enter the size of the stack
    cout << "Enter Size Of Stack" << endl;
    cin >> size;
    Stack s(size);

    do
    {
        cout << "1.Top\n2.Push\n3.Peek\n4.isEmpty\n5.pop\n6.size\nEnter 7 to exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "The Index of Top :" << s.get_top() << endl;
            break;
        case 2:
            cout << "Enter Element To Push in Stack" << endl;
            cin >> element;
            s.push(element);
            break;
        case 3:
            cout << "The Element at Top :" << s.peek() << endl;
            break;
        case 4:
            s.is_empty();
            break;
        case 5:
            cout << "The Element has been poped" << endl;
            cout << "Poped Element:" << s.pop() << endl;
            break;
        case 6:
            cout << "The size of Stack:" << s.get_size() << endl;
        case 7:
            break;
        default:
            cout << "Enter a Valid Input" << endl;
            break;
        }
        printStack(s);
    } while (ch != 7);
}
/*********************************************
 *Time Complexity of Whole Program O(n)*number of operations performed by user
 where n is the current size of stack
 *Space Complexity of the whole program is O(n)
 where n is the size given by user
 **********************************************/
