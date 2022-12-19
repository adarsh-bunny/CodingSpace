#include<bits/stdc++.h>
using namespace std;
void substring(string str,string output)
{
    if(str.size()==0)
    {
        cout<<output<<" ";
        return;
    }
    substring(str.substr(1),output);
    substring(str.substr(1),output+str[0]);

}

int main(){
    string str="abc";
    int l=str.length();
    int n=pow(l,2);
  //  string *output= new string[n];
  string output ="";
    substring(str,output);
}