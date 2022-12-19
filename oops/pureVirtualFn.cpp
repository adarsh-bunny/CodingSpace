#include <bits/stdc++.h>
using namespace std;

// pure virtual function -> contains only name/declaration and  no definition
class Vehicle{
    public:
    virtual void print()=0;
};
// class having pure virtual function are called abstract classes
//abstract class are those whose object cant be instantiated as it contains no defintion for function present(incomplete function).

class Car:public Vehicle{
    public:
     void print()  // if not implemented in derived class then it will also become abstract class
    {
        cout<<"Car class " <<endl;
    }
};
int main()
{
   Vehicle v;
  
}