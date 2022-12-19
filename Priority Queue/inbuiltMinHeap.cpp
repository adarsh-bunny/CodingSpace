#include <bits/stdc++.h>
using namespace std;

int main()
{
   priority_queue<int,vector<int> ,greater<int>> pq; 
      pq.push(116);
    pq.push(1);
    pq.push(167);
    pq.push(7);
    pq.push(45);
    pq.push(32);
    pq.push(88);

    cout<<"Size :"<<pq.size()<<endl;
    cout<<"Top :"<<pq.top()<<endl;

    while(!pq.empty())
    {
        cout<<pq.top()<<endl;
        pq.pop();
    }
}