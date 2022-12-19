#include<bits/stdc++.h>
using namespace std;

class Parent
{
    public:
    int data;
}

class child:public Parent
{
 public:
 int id;
}

int main()
{
    child obj;
    obj.data=2;
    obj.id=0;

}

//operator overloading

class Complex{
    private:
    int real, imag;
    public:
    Complex(int real,int img)
    {
        real = r;   imag = i;
    }

    Complex  operator+(Complex const &obj)
    {
        Complex res;
        res.real= real+obj.real;
        res.img=img + obj.img;

        return res;
    }

}

int main()
{
    Complex c1(2,5),c2(8,7);
    Complex c3= c1+c2;
}

//runtime polymorphism

class Base
{
    public:
    void print()
    {
        cout<<"Base class print";
    }

    void show()
    {
        cout<<"Base class show";
    }
}

class Derivedclass:public Base{
    public:
     virtual void print()
    {
        cout<<"Base class print";
    }

    void show()
    {
        cout<<"Base class show";
    }
}

int main()
{
    Base *ptr;
    Derived obj;
    *ptr=&obj;
    
    ptr->print();
    ptr->show();

}