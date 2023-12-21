/***************************************
 * Name:Abhishek Raje
 * Roll No:BM22BTECH11002
 * Assignment 1
 * Question 2
 ****************************************/
#include <iostream>
using namespace std;
/**************************************************************
 * Creating a Class Queue containing the properties and methods
 **************************************************************/
class Queue
{
public:
    // defineing the properties of queue
    int front;
    int back;
    int size;
    int *arr;
    // creating the constructor defining the initial properties of queue
    Queue(int size)
    { // properties of the queue
        this->size = size;
        this->front = this->back = 0;
        this->arr = new int[size];
    }
    /************************************************************
     * returns true  if the the queue is full else returns false
     ***************************************************************/
    bool is_full()
    {
        if (this->back == this->size)
        {
            cout << "Queue Overflow" << endl;
            return true;
        }
        return false;
        // time complexity O(1)
    }
    /************************************************************
     * returns true  if the the queue is empty else returns false
     ***************************************************************/
    bool is_empty()
    {
        if (this->back == this->front)
        {
            cout << "Queue Underflow" << endl;
            return true;
        }
        return false;
        cout << "Queue is not Empty" << endl;
        // time complexity O(1)
    }
    /*****************************************
     * pushes the element in the queue
     ******************************************/
    void push(int element)
    {
        if (is_full())
        {
            // returns the function in case the queue  is full
            return;
        }
        // updates the  value of back pointer and inserts the element in the queue
        this->arr[this->back] = element;
        this->back++;
        // time complexity O(1)
    }
    /*****************************************
     * pushes the element in the queue by creating pointer to element
     ******************************************/
    void emplace(int &element)
    {
        if (is_full())
        {
            // returns the function in case the queue  is full
            return;
        }
        // updates the  value of back pointer and inserts the element in the queue
        this->arr[this->back] = element;
        this->back++;
        // time complexity O(1)
    }
    /*****************************************
     * pops the element present at the front pointer
     ******************************************/
    int pop()
    {
        if (is_empty())
        {
            this->front = this->back = 0;
            return -1;
        }
        // returns the poped element
        int poped_element = this->arr[this->front];
        // updates the front pointer
        this->front++;
        return poped_element;
        // time complexity O(1)
    }
    /******************************************************
     * returns the position of front pointer of the queue
     *******************************************************/
    int get_front()
    {
        // returns front pointer of the current object
        return this->front;
        // time complexity O(1)
    }
    /******************************************************
     * returns the size of the queue
     *******************************************************/
    int get_size()
    {
        return this->back - this->front;
        // time complexity O(1)
    }
};
/******************************************************
 * prints the Queue from front to back
 *******************************************************/
void printQ(Queue q)
{
    cout << "Queue Currently" << endl;
    for (int i = q.front; i < q.back; i++)
    {
        cout << q.arr[i] << "\t";
    }
    cout << endl;
    // time complexity O(n)
    // where n is the size of the queue
}
int main()
{
    int size, element, ch;
    ch = 0;
    // prompting user to enter size
    cout << "Enter Size of Queue" << endl;
    cin >> size;
    // creating Object q
    Queue q(size);
    do
    {
        cout << "1.Front\n2.Push\n3.isEmpty\n4.pop\n5.size\n6.Emplace\nEnter 7 to exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "The Index of Front :" << q.get_front() << endl;
            break;
        case 2:
            cout << "Enter Element To Push in Queue" << endl;
            cin >> element;
            q.push(element);
            break;
        case 3:
            q.is_empty();
            break;
        case 4:
            cout << "The Element has been poped" << endl;
            cout << "Poped Element:" << q.pop() << endl;
            break;
        case 5:
            cout << "The size of Stack:" << q.get_size() << endl;
            break;
        case 6:
            cout << "Enter Element To Emplace in Queue" << endl;
            cin >> element;
            q.emplace(element);
            break;
        case 7:
            break;
        default:
            cout << "Enter a Valid Input" << endl;
            break;
        }

        printQ(q);
    } while (ch != 7);
}

/*********************************************
 *Time Complexity of Whole Program O(n)*number of operations performed by user
 *where n is the size of queue
 *Space Complexity of the whole program is O(n)
 where n is the size of the array
 **********************************************/