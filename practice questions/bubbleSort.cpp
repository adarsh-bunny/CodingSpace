#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b)
{
    int temp=*a;
     *a=*b;
     *b=temp;
    
}
void bubbleSort(int arr[], int s)
{
    for(int i=0;i<s-1;i++)
    {
        for(int j=0;j<s-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            swap(&arr[j],&arr[j+1]);
        }
    }
}

int main()
{
    int arr[] = {3, 5, 1, 8, 2, 4, 9, 22, 10};
    int s = sizeof(arr) / sizeof(arr[0]);
    
    cout << "size of array " << s << endl;

    bubbleSort(arr,s);
    for (int i = 0; i < s; i++)
    {
        cout << arr[i] << endl;
    }
}