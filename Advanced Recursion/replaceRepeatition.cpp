#include<bits/stdc++.h>

using namespace std;

void replaceRepetition(char s[])
{
    if(s[0]=='\0')
    return;


    replaceRepetition(s+1);
        if(s[0]==s[1])
    {
        int i=1;
        for(;s[i]!='\0';i++)
        {
            s[i-1]=s[i];
        }
        s[i-1]='\0';
      //  replaceRepetition(s);
    }
}


int main()
{
    char ch[]="abbbbbvxxxcvbbbbd";


    replaceRepetition(ch);

    cout<<ch<<endl;
    
}
