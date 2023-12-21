/**************************************************
 * Name:Abhishek Raje
 * Roll No:BM22BTECH11002
 * Assignment 5
 * Question 4
 ***************************************************/
#include <iostream>
#include <algorithm>
using namespace std;

class heap
{
public:
    int arr[100];
    int heap_size;

    heap()
    {
        heap_size = 0;
    }

    void insert(int val)
    {
        heap_size++;
        int index = heap_size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] > arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void heapify()
    {
        for (int i = heap_size / 2; i >= 1; i--)
        {
            int current = i;
            while (current <= heap_size / 2)
            {
                int left = 2 * current;
                int right = 2 * current + 1;
                int smallest = current;

                if (left <= heap_size && arr[left] < arr[smallest])
                {
                    smallest = left;
                }

                if (right <= heap_size && arr[right] < arr[smallest])
                {
                    smallest = right;
                }

                if (smallest != current)
                {
                    swap(arr[current], arr[smallest]);
                    current = smallest;
                }
                else
                {
                    break;
                }
            }
        }
    }
    /**************************************************
     * Find smallest poisitve number after heapify
     ***************************************************/
    int findSmallestPositive()
    {
        heapify();
        int smallestPositive = -1; 

        for (int i = 1; i <= heap_size; i++)
        {
            if (arr[i] > 0 && (smallestPositive == -1 || arr[i] < smallestPositive))
            {
                smallestPositive = arr[i];
            }
        }

        return smallestPositive;
    }

    void delete_heap()
    {
        if (heap_size == 0)
        {
            cout << "Heap is Empty" << endl;
            return;
        }

        arr[1] = arr[heap_size];
        heap_size--;
        heapify();
    }
};

int main()
{
    heap h;
    int n, val;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the Elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        h.insert(val);
    }

    int smallestPositive = h.findSmallestPositive();
    cout << "Smallest Positive Integer: " << smallestPositive << endl;

    return 0;
}
