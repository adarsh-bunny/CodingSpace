#include <bits/stdc++.h>
using namespace std;

class PriorityQueue
{
    vector<int> pq;

public:
    PriorityQueue()
    {
    }
    bool isEmpty()
    {
        return pq.size()==0 ;
    }

    //Return the size of prorityQueue- no. of elements present
    int getSize()
    {
        return pq.size();
    }

    int getMax()
    {
        if (isEmpty())
        {
            return 0; //Priority Queue is empty
        }
        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element);
        int childIndex = pq.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] > pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int removeMax()
    {
        if (isEmpty())
        {
            return 0; //Priority Queue is empty
        }
        int ans = pq[0];
        int lastIndex = pq.size() - 1;
        pq[0] = pq[lastIndex];
        pq.pop_back();
        // down-heapify
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        while (leftChildIndex < pq.size())
        {
            int maxIndex = parentIndex;

            if (pq[leftChildIndex] > pq[maxIndex])
                maxIndex = leftChildIndex;
            if (rightChildIndex < pq.size() && pq[rightChildIndex] > pq[maxIndex])
                maxIndex = rightChildIndex;

            if (maxIndex == parentIndex)
            {
                break;
            }
            //swap
            int temp = pq[maxIndex];
            pq[maxIndex] = pq[parentIndex];
            pq[parentIndex] = temp;
            //update
            parentIndex = maxIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }

        return ans;
    }
};