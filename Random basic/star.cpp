#include<bits/stdc++.h>
using namespace std;

int main()
{
    for(int i = 6; i >= 0; i--)
    {
        for (int s = i; s < 6; s++)
        {
            cout << " ";
        }
        for(int j=0;j<=2*i;j++)
        cout<<"*";
        cout<<endl;
    }
}