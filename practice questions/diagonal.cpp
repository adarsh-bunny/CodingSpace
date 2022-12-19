#include<bits/stdc++.h>
using namespace std;
int diagonalDifference(vector<vector<int>> arr) {

    int leftdia=0;
    int j=arr[0].size()-1;
    cout<<"value of j "<<j<<endl;

    int  rightdia=0;
    for(int i=0;i<arr.size();i++)
        leftdia+=arr[i][i];
    cout<<"value of left "<<leftdia<<endl;

          for(int i=0;i<arr.size();i++)   
          {
              rightdia+=arr[i][j];
              j--; 
          } 
        
        cout<<"value of right "<<rightdia<<endl;     
    return abs(rightdia-leftdia);
              
          
}
int main()
{

int n =3;
vector<vector<int>> arr={{11, 2, 4},
{4 ,5, 6},
{10, 8 ,-12}};
cout<<diagonalDifference(arr);}