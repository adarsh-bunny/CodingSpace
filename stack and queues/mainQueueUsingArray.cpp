#include <bits/stdc++.h>
////#include "QueueUsingArray.h"
#include "QueueLL.h" 
#include <queue>

using namespace std;
  int main(){
    //   Queue<char> s;
    //   s.enqueue(101);
    //   s.enqueue(102);
    //   s.enqueue(103);
    //   s.enqueue(104);
    //     s.enqueue(105);
    // cout<<s.front()<<endl;
    // cout<<"size "<<s.getSize()<<endl;


    //  cout<<s.dequeue()<<endl;
    //  cout<<s.dequeue()<<endl;
    //  cout<<s.dequeue()<<endl;
    //  cout<<s.dequeue()<<endl;
    //  cout<<s.dequeue()<<endl;
    //  cout<<s.dequeue()<<endl;
    //   cout<<"size "<<s.getSize()<<endl;
    //    cout<<"size "<<s.isEmpty()<<endl;
  queue<int> s;
    s.push(101);
      s.push(102);
      s.push(103);
      s.push(104);
        s.push(105);

        while(!s.empty())
        {
             cout<<s.front()<<endl;    
            s.pop();
        }



  }