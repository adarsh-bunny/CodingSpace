#include <bits/stdc++.h>
#include "stackusingLL.cpp"

using namespace std;
bool checkRedundant(char *exp)
{
    stack<char> s;
    int count=0;

    int len = strlen(exp);

    for (int i = 0; i < len; i++)
    {
        if(exp[i]!=')')
        {
            if(exp[i]!='(')
            {
                
               s.push(exp[i]);

            }
            else
            {
                s.push(exp[i]);
            }
            
        }
        else if(exp[i]=='(')
        {
            int j=i-1;
            while(exp[j]!='(')
            {
                s.pop();
                count++;
                j--;
            }
            
            if(count==0)
            return true;
            else 
             count=0;
            
        }

    
    }

  return false;
}
int main()
{
    char c[] = "((a+b))";

    cout << std::boolalpha<<checkRedundant(c);
}