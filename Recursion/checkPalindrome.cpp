#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s)
{
    int i=0,j=s.size()-1;
    cout<<"size: "<<j<<endl;
    while(i<=j)
    {
        if(s[i]!=s[j])
        {
            cout<<s[i]<<" "<<s[j]<<endl;
  return false;
        }
      

        i++,j--;
    }

return true;

}


int main()
{

    string s;
    cin>>s;
    

   // ==================================== Method 1=======================
  /* string temp=s;
    reverse(s.begin(),s.end());
    if(s==temp)
    cout<<"true"<<endl;
    else
    cout<<"false"<<endl;*/


// ==================================== Method 2=======================
    cout<<checkPalindrome(s);



}