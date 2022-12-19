#include<bits/stdc++.h>
using namespace std;


int partition(int *arr,int si,int ei)
{
    int pe=arr[si];

    int count=0;
    for(int i=si+1;i<=ei;i++)
    {
        if(pe>=arr[i])
        count++;
    }
    int pi=si+count;

    int temp=arr[pi];
    arr[pi]=pe;
    arr[si]=temp;


    int i=si,j=ei;
    while(i<=pi && j>=pi)
    {
       while(arr[i]<=pe)
       i++;
       while(arr[j]>pe)
       j--;
       	if(i<pi && j>pi)
		{
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			i++;
			j--;
		}

    }
    return pi;
}

void quickSort(int *input,int si,int ei)
{
  if(si>=ei)
  return; 
  int c=partition(input,si,ei);
  quickSort(input,si,c-1);
  quickSort(input,c+1,ei);


}

int main()
{
    int n;
  cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, 0,n-1);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;
}