
#include <bits/stdc++.h>
using namespace std;

int *replaceValues(int arr[],int len)
{
    int i,j;
    if(len%2==0)
    {
          for (i = 0; i < len; i++)
        {
          arr[i]=0;
        }

    }
    else{
        for(j=0;j<len;j++)
        arr[j]=1;
    }
    return arr;
 
}


int main()
{
    int arr[]={1,2,8,6};
    int x = 0;

   // printPattern(5);
   replaceValues(arr,4);
    // cout<<*p<<s[1];
    for(int j=0;j<4;j++)
    {
        cout<<"output"<<arr[j]<<" ";
    }

}