/***************************************
 * Name:Abhishek Raje
 * Roll No:BM22BTECH11002
 * Assignment 1
 * Question 6
 ****************************************/
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
/***************************************
 * Function to remove adjacent characters
 ****************************************/
void remove_add_char(string &input_str, stack<char> &s, string &prev_input_str)
{
    // intializing a string to store the value in previosu recursion
    prev_input_str = "";
    for (int i = input_str.length() - 1; i > -1; i--)
    {
        // making exceptional case for i=0 and i =length-1
        if (i == 0 && input_str[i] != input_str[i + 1])
        {
            s.push(input_str[i]);
        }
        else if (i == input_str.length() - 1 && input_str[i] != input_str[i - 1])
        {
            s.push(input_str[i]);
        }
        // pushing non consesqutive elements in the stack
        else if (input_str[i] != input_str[i + 1] && input_str[i] != input_str[i - 1] && i != input_str.length() - 1 && i != 0)
        {
            s.push(input_str[i]);
        }
    }
    // transfering elements of the stack to the previous string
    while (!s.empty())
    {
        prev_input_str += s.top();
        s.pop();
    }
    // returning the input string if no can in size is obserevd in the previous and final string

    if (prev_input_str.length() == input_str.length())
    {
        cout << "Output String :" << input_str << endl;
        return;
    }
    // rcursively removing adjacent characters
    remove_add_char(prev_input_str, s, input_str);
    // time complexity O(n)
}
int main()
{
    stack<char> s;
    string input_str, final_str;
    cout << "Enter Input String :";
    cin >> input_str;
    remove_add_char(input_str, s, final_str);
}
/*********************************************
 *Time Complexity of Whole Program O(n)
 *Space Complexity of the whole program is O(n)
 where n is the length of input string
 **********************************************/