#include <bits/stdc++.h>
using namespace std;
void printPattern(int num)
{
    int i, print = 0;
    if (num % 2 == 0)
    {
        print = 0;
        for (i = 0; i < num; i++)
        {
            cout << print << " ";
            print += 2;
        }
    }
    else
    {
        print = 1;
        for (i = 0; i < num; i++)
        {
            cout << print << " ";
            print += 2;
        }
    }
}
void replaceValues(int arr[],int len)
{
    int i,j;
    if(len%2==0)
    {
          for (i = 0; i < len; j+2)
        {
          arr[j]=1;
        }

    }
    else{
        for(j=0;j<len;j+2)
        arr[j]=1;
    }
 
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
// int main()
// {
// 	int n,i,j;

//     cin>>n;

// 	//LOOP FOR HUT PYRAMID
// 	for(i=0,j=0;i<n;j++)
// 	{
// 		if(j==n+i)
// 		{
// 			j=-1;
// 			++i;
// 			cout<<"\n";
// 		}

// 		// print Center Star triangle
// 		else if((i+j)>=n-1)
// 		{
// 			cout<<"*";
// 		}
// 		else
// 			cout<<" ";
// 	}

// 	//LOOPS FOR LOWER WALLS
// 	for(int k=0;k<5;k++)
// 	{
// 		// Left and right rectangle
// 		for(int l=0;l<n-1+i;l++)
// 		{
// 			if(l<2 || (l<n-1+i && l>n-4+i))
// 				cout<<"*";
// 			else
// 				cout<<" ";
// 		}
// 		cout<<endl;
// 	}

//     for(int k=0;k<2;k++)
// 	{
// 		// Left and right rectangle
// 		for(int l=0;l<1+(n-1)*2;l++)
// 		{
// 				cout<<"*";
// 		}
// 		cout<<endl;
// 	}

// }