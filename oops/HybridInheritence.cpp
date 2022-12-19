#include<bits/stdc++.h>
using namespace std;
class Vehicle{
    private:
    int maxSpeed;
    protected:
    int numTyres;
    public:
    string color;

    Vehicle()
    {
        cout<<"Vehicle's default Constructor"<<endl;
    }
      Vehicle(int z)
    {
        cout<<"Vehicle's Pramaterized Constructor"<<endl;
        maxSpeed=z;
    }
    void print()
    {
        cout<<"Vehicle class : "<<endl;
    }
    
    ~Vehicle()
    {
        cout<<"Vehicle's default destructor"<<endl;
    }
    
};


class Car:public Vehicle
{
    public:
    int numGears;

    Car ()
    {
        cout<<"Car's default constructor"<<endl;
    }


   void print()
    {
        cout<<"numTyres: "<<numTyres<<endl;
        cout<<"Color: "<<color<<endl;
        cout<<"Num Gears: "<<numGears<<endl;

    }
     ~Car ()
    {
        cout<<"Car's default destructor"<<endl;
    }
 

};


class Truck:public Vehicle
{
    public:

    Truck ()
    {
        cout<<"Truck's default constructor"<<endl;
    }
     void print()
    {
        cout<<"Truck Class: "<<endl;
    }

     ~Truck ()
    {
        cout<<"Car's default destructor"<<endl;
    }
   

};

class Bus:public Car,public Truck{

    public:
    Bus()
    {
        cout<<"Bus Constructor"<<endl;
    }

     ~Bus()
    {
        cout<<"Bus destructor"<<endl;
    }
};

int main()
{
Bus b;
}