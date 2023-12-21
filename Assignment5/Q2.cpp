/**************************************************
 * Name:Abhishek Raje
 * Roll No:BM22BTECH11002
 * Assignment 5
 * Question 2
 ***************************************************/
#include <iostream>
using namespace std;

class MinHeap
{
public:
    int arr[100];
    int heap_size;

    MinHeap()
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

class MaxHeap
{
public:
    int arr[100];
    int heap_size;

    MaxHeap()
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
            if (arr[parent] < arr[index])
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
                int largest = current;

                if (left <= heap_size && arr[left] > arr[largest])
                {
                    largest = left;
                }

                if (right <= heap_size && arr[right] > arr[largest])
                {
                    largest = right;
                }

                if (largest != current)
                {
                    swap(arr[current], arr[largest]);
                    current = largest;
                }
                else
                {
                    break;
                }
            }
        }
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
/**************************************
 * Function to return the kth smallest element
 **************************************/
int findKthSmallest(int arr[], int n, int k)
{
    MinHeap minHeap;

    for (int i = 0; i < n; i++)
    {
        minHeap.insert(arr[i]);
    }

    for (int i = 0; i < k - 1; i++)
    {
        minHeap.delete_heap();
    }
    // Time Complexity:O(n)

    return minHeap.arr[1];
}
/**************************************
 * Function to return the kth largest element
 **************************************/
int findKthLargest(int arr[], int n, int k)
{
    MaxHeap maxHeap;

    for (int i = 0; i < n; i++)
    {
        maxHeap.insert(arr[i]);
    }

    for (int i = 0; i < k - 1; i++)
    {
        maxHeap.delete_heap();
    }

    return maxHeap.arr[1];
    // Time Complexity:O(n)
}

int main()
{
    int n, k;

    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[100];

    cout << "Enter the array elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    cout << "The " << k << "th smallest element is: " << findKthSmallest(arr, n, k) << endl;
    cout << "The " << k << "th largest element is: " << findKthLargest(arr, n, k) << endl;

    return 0;
}
