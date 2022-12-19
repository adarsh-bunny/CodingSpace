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
    Car c;
    c.print();

}