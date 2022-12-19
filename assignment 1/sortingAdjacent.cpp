#include<bits/stdc++.h>
using namespace std;

void swap(int &i,int &j)
{
    int temp=i;
     j=i;
     i=temp;

}
bool isSorted(int *arr,int n)
{
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        return false;
    }
    return true;
}
bool checker(int *arr,int n)
{
    for(int i=0;i<n-1;i++)
      {
        if(arr[i]-1==arr[i+1])
        {
            swap(arr[i],arr[i+1]);

        }
      }

      if(isSorted(arr,n))
      {
        return true;
      }
     else 
     return false;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int* arr = new int[n];
		for(int i=0; i<n; i++)
		{
			cin >> arr[i];
		}
		if(checker(arr, n))
		{
			cout << "Yes"<<endl;
		}
		else
		{
			cout << "No"<<endl;
		}
	}
}