#include <bits/stdc++.h>
#include <queue>
#include <bits/stdc++.h>
#include <stack>
using namespace std;

void reverseQueue(queue<int> &q) {
    if(q.empty())
        return ;
    
    int data = q.front();
    
    q.pop();
    reverseQueue(q); 
    q.push(data);
    
}
void printQueue(queue<int> Queue)
{
    while (!Queue.empty()) {
        cout << Queue.front() << " ";
        Queue.pop();
    }
}
int main()
{
    queue<int> q;
    q.push(11);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(10);
    printQueue(q);
    cout<<endl;
    reverseQueue(q); 

    cout<<q.front()<<endl;
   // cout<<s.pop()<<endl;
    printQueue(q);

    
 
}
