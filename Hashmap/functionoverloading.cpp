#include <bits/stdc++.h>
using namespace std;

class Base{
    public:
   virtual void print()
    {
        cout<<" Base class function: print "<<endl;
    }

    void show()
    {
        cout<<"Show function in base class: "<<endl;
    }
};

class Child:public Base
{
    public:
        void print()
    {
        cout<<" Child class function: print "<<endl;
    }

    void show()
    {
        cout<<"Show function in child class: "<<endl;
    }

};

int main()
{
    Base *b= new Child();
    b->print();

    Base *bptr;
    Child d;
    bptr = &d;
   bptr->print();
}