#include <bits/stdc++.h>
using namespace std;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int main()
{
    int arr[]={1,3,4,2};
    int n=sizeof(arr)/sizeof(arr[0]);

       int i, j,count=0;
    for (i = 0; i < n-1; i++)    
     
    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1]){
            swap(&arr[j], &arr[j+1]);
            count++;

        }
        cout<<count<<endl;
}