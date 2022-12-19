#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high)
{

    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element

            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int a[], int start, int end)
{
    if (start > end)
        return;
    // cout << " i " << start << " l " << end << endl;

    int i = partition(a, start, end);
    cout << i << " s " << start << " l " << end << endl;
    //int mid = end + start / 2;
    quickSort(a, start, i - 1);
    quickSort(a, i + 1, end);
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
    quickSort(a, 0, l - 1);
    cout << endl;
    cout << "After merge" << endl;
    for (int i = 0; i < l; i++)
    {
        cout << a[i] << " ";
    }
}
