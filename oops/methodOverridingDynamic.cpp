#include <bits/stdc++.h>
using namespace std;


class Vehicle{
    public:
    void print()
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

    v2->print(); // vehicle :  print function as decides in compile time 

}