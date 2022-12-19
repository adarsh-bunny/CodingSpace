// Coding Problem
// Problem Statement: Inplace Heap sort
// Problem Level: MEDIUM
// Problem Description:
// Given an integer array of size n. Sort this array (in decreasing order) using heap sort.
// Space complexity should be O(1).
// Input Format :
// Line 1 : Integer n, Array size
// Line 2 : Array elements, separated by space

// Output Format :
// Array elements after sorting

// Constraints :
// 1 <= n <= 10^6

// Sample Input:
// 6 
// 2 6 8 5 4 3

// Sample Output:
// 8 6 5 4 3 2



#include <bits/stdc++.h>
using namespace std;

void inplaceHeapSort(int pq[], int n)
{
    //down heapify
    for (int i = 1; i < n; i++)
    {
        int childIndex = i;
        while(childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
                break;

            childIndex = parentIndex;
        }
    }
    // removing element
    int size = n;
    while(size>1)
    {

    int temp = pq[0];
    pq[0] = pq[size - 1];
    pq[size - 1] = temp;
    size--;

    // down-heapify
    int parentIndex = 0;
    int leftChildIndex = 2 * parentIndex + 1;
    int rightChildIndex = 2 * parentIndex + 2;
    while (leftChildIndex < size)
    {
        int minIndex = parentIndex;

        if (pq[leftChildIndex] < pq[minIndex])
            minIndex = leftChildIndex;
        if (rightChildIndex <size && pq[rightChildIndex] < pq[minIndex])
            minIndex = rightChildIndex;

        if (minIndex == parentIndex)
        {
            break;
        }
        //swap
        int temp = pq[minIndex];
        pq[minIndex] = pq[parentIndex];
        pq[parentIndex] = temp;
        //update
        parentIndex = minIndex;
        leftChildIndex = 2 * parentIndex + 1;
        rightChildIndex = 2 * parentIndex + 2;
    }

    }
}

int main()
{
    int n = 5;
    int arr[] = {5, 1, 2, 0, 8};
    // for(int i=0;i<5;i++)
    // {
    //     cin>>arr[i];
    // }
    inplaceHeapSort(arr, n);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}