#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string str, int start, int end) {
    if(str[0] == '\0' || str[1] == '\0') {
        return true;
    }
    if(start >= end) {
        return true;
    }
    if(str[start] == str[end]) {
        return checkPalindrome(str, start+1, end - 1); 
    } 
    else { 

        return false;
    }
}


int main()
{
    int n;
    string str={"aaaa"};
    cout<<str.size()<<endl;
    bool res=checkPalindrome(str,0,str.size()-1);
     cout<<res<<endl;
    if (res)
        cout << str << " is a  Palindrome number" << endl;
    else
        cout << str << " is not a  Palindrome number" << endl;
}