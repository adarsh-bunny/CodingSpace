#include<bits/stdc++.h>

using namespace std;

void replace(char s[],char b, char r)
{
    if(s[0]=='\0')
    return;

    if(s[0]==b) s[0]=r;
    replace(s+1,b,r);
}


int main()
{
    char ch[]="abvcvbbbbd";
    char f='b';
    char r='x';

    replace(ch,f,r);

    cout<<ch<<endl;
    
}
