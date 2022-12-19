#include<bits/stdc++.h>
using namespace std;


string remVowel(string str) 
{
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u',
                           'A', 'E', 'I', 'O', 'U'};
    int i;
    for ( i = 0; i < str.length()-1; i++) 
    {
        if(tolower(str[i])=='a' ||tolower(str[i])=='e'||tolower(str[i])=='i'||tolower(str[i])=='o'|| tolower(str[i])=='u' )
        i=i+2;
        
            if (find(vowels.begin(), vowels.end(),
                      str[i]) != vowels.end()) 
        {
            str = str.replace(i, 1, "");
            i -= 1;
        }

        
        
    }
    if (find(vowels.begin(), vowels.end(),
                      str[i]) != vowels.end() ) 
        {
            str = str.replace(i, 1, "");
            i -= 1;
        }
    return str;
}

int main() 
{
    // string str = "GeeeksforGeeks - A Computer"
    //              " Science Portal for Geeks";
    string str="Heeo";
    cout << remVowel(str) << endl;

    return 0;
}
