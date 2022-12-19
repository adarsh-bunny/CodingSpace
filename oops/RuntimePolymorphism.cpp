#include <bits/stdc++.h>
using namespace std;

// run time polymorphism using virtual function
class Vehicle{
    public:
    virtual void print()
    {
        cout<<"Vehicle class " <<endl;
    }
};


class Car:public Vehicle{
    public:
     void print()
    {
        cout<<"Car class " <<endl;
    }
};
int main()
{
   Vehicle v;
   v.print();
   
    Car c;
    c.print();

    Vehicle *v1= new Vehicle;  //dynamic allocation
    Vehicle *v2;
  //  v2=&v;
    v2=&c;     // this is valid base class pointer can points to derived class but not vice versa;
    v1->print(); //vehicle 
    v2->print(); // car :  print function as decides in run time 
   // similarly
      Vehicle *v3= new Car;
      v3->print();


}