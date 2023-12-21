/***************************************
 * Name:Abhishek Raje
 * Roll No:BM22BTECH11002
 * Assignment 1
 * Question 3
 ****************************************/
#include <iostream>
#include <stack>
using namespace std;
/************************************************************
 * returns true if the string is beautiful else returns false
 ************************************************************/
bool is_balanced(string brackets)
{
    // creating object s
    stack<char> s;
    // going through the entire string using loop
    for (int i = 0; i < brackets.length(); i++)
    {
        // pushing element in the stack if there is a opening bracket
        if (brackets[i] == '{' || brackets[i] == '(' || brackets[i] == '[')
        {
            s.push(brackets[i]);
        }
        // poping element from the stack if there is a closing bracket
        else if (brackets[i] == '}' || brackets[i] == ')' || brackets[i] == ']')
        {
            // Check if the stack is empty (no matching opening bracket)
            if (s.empty())
            {
                return false;
            }

            char top = s.top();
            if ((brackets[i] == '}' && top == '{') || (brackets[i] == ')' && top == '(') || (brackets[i] == ']' && top == '['))
            {
                s.pop();
            }
            else
            {
                return false; // contition for  Mismatched  bracket
            }
        }
        // if the stack is empty after the entire operation the string is balanced
        if (s.empty())
        {
            return true;
        }
        return false;
        // time complexity O(n)
        // where n is the length of string
    }
}
int main()
{
    string brackets;
    // prompting user to enter string
    cout << "Enter String" << endl;
    cin >> brackets;
    if (is_balanced(brackets))
    {
        cout << "String is Beautiful" << endl;
    }
    else
    {
        cout << "String is Not Beautiful" << endl;
    }
}

/*********************************************
 *Time Complexity of Whole Program O(n)
 *Space Complexity of the whole program is O(n)
 where n is the length of string input by the user
 **********************************************/