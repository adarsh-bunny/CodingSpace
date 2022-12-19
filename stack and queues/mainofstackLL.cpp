#include <bits/stdc++.h>
#include "stackusingLL.cpp"

using namespace std;

int main()
{
    Stack<char> s;
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);
    s.push(65 );

    cout << s.size() << endl;
    cout << s.top() << endl;
      cout << s.top() << endl;

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.top() << endl;
}