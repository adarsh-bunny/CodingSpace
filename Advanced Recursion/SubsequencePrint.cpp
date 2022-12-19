#include<bits/stdc++.h>
using namespace std;


void subsequence(string input, string output)
{
    if(input.empty())
    {
        cout<<output<<endl;
        return;
    }

    subsequence(input.substr(1),output);
    subsequence(input.substr(1),output+input[0]);
    return;
   
}
int main()
{
    string input;
    cin>>input;
   string output;
     subsequence(input,output);


}