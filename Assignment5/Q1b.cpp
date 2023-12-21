/**************************************************
 * Name: Abhishek Raje
 * Roll No: BM22BTECH11002
 * Assignment 5
 * Question 1
 **************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

/**************************************************
 * Creating heap class
 **************************************************/
class heap
{
public:
    int arr[100];
    int heap_size;

    heap()
    {
        heap_size = 0;
        arr[0] = 1000000; // Set a large value as the initial element for Min Heap
    }

    /**************************************************
     * Function to insert value in heap
     **************************************************/
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
        // Time Complexity: O(log n)
    }

    /**************************************************
     * Function to print heap
     **************************************************/
    void printHeap()
    {
        for (int i = 1; i <= heap_size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        // Time Complexity: O(n)
    }

    /**************************************************
     * Function to Heapify a array
     **************************************************/
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
        // Time Complexity: O(n)
    }

    /**************************************************
     * Delete the last index of heap
     **************************************************/
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
        // Time Complexity: O(n)
    }

    /**************************************************
     * Find the smallest element in the heap
     **************************************************/
    int findSmallest()
    {
        if (heap_size == 0)
        {
            cout << "Heap is Empty" << endl;
            return -1;
        }
        return arr[1];
    }
};

int main()
{
    heap h;
    int choice, val, smallest;

    while (true)
    {
        cout << "Implementation of Min Heap:\n";
        cout << "1. Insert\n";
        cout << "2. Heapify\n";
        cout << "3. Delete\n";
        cout << "4. Find Smallest\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            h.insert(val);
            break;

        case 2:
            h.heapify();
            cout << "Heapified.\n";
            break;

        case 3:
            h.delete_heap();
            cout << "Element deleted from the heap.\n";
            break;

        case 4:
            smallest = h.findSmallest();
            cout << "Smallest element in the heap: " << smallest << endl;

            break;

        case 5:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
        cout << "Heap: ";
        h.printHeap();
    }
}
