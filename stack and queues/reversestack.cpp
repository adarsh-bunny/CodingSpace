#include <bits/stdc++.h>
#include <stack>

using namespace std;
#include <stack>
void reverseStack(stack<int> &s1, stack<int> &s2) {
    if(s1.size() <= 1)
        return ;
    
    int lastElem = s1.top();
    
    s1.pop();
    reverseStack(s1,s2);
    while(!s1.empty()){
        int a = s1.top();
        s1.pop();
        s2.push(a);
    }
    s2.push(lastElem);
    
    while(!s2.empty()){
        int a = s2.top();
        s2.pop();
        s1.push(a);
    }
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(10);

    stack<int> s2;
    while(!s.empty())
    {
        s2.push(s.top());
        s.pop();

    }
    s=s2;
   cout<<s2.top()<<endl;
   cout<<s.top()<<endl;
}
