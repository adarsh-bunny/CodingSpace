#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]

    // Initial index of first subarray
    int i = 0;

    // Initial index of second subarray
    int j = 0;

    // Initial index of merged subarray
    int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int a[], int start, int end)
{
    if (start >= end)
        return;
    // cout << " i " << start << " l " << end << endl;

    int mid = start + (end - start) / 2;
    cout << mid << " s " << start << " l " << end << endl;
    //int mid = end + start / 2;
    mergeSort(a, start, mid);
    mergeSort(a, mid + 1, end);
    merge(a, start, mid, end);
}
int main()
{
    int a[] = {2, 5, 12, 6, 13, 8, 4, 23};

    int l = sizeof(a) / sizeof(a[0]);
    cout << l << endl;
    cout << "before merge" << endl;
    for (int i = 0; i < l; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    mergeSort(a, 0, l - 1);
    cout << endl;
    cout << "After merge" << endl;
    for (int i = 0; i < l; i++)
    {
        cout << a[i] << " ";
    }
}
