#include<bits/stdc++.h>
using namespace std;
class Teacher
{
    public:
    string name;
    int age;
    void print()
    {
        cout<<"Teacher class"<<endl;
    }
      void printAge()
    {
        cout<<"Teacher age is "<<endl;
    }
};
class Student
{
    public:
       void print()
    {
        cout<<"Student class"<<endl;
    }
     void printAge()
    {
        cout<<"Student age is "<<endl;
    }

};

class TA:public Teacher,public Student   //Teacher assistant
{
    public:
    void printAge()
    {
        cout<<"TA age is "<<endl;
    }

};

int main()
{


 TA t;
 //t.print();  // error in compilation

 // use scope resolution
 
 t.Student :: print();
 t.printAge(); ///no error

 t.Teacher :: name="POPAT";

}