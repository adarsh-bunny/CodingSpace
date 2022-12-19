#include <bits/stdc++.h>
using namespace std;

/*
// function overloading
int test();
int test(int a);
int test(int a,int b);
void test() // this is not a function overloading
*/

class Complex
{
    int real;
    int img;
    public:
    Complex(int r=0,int i=0)
    {
        real=r;
        img=i;
    }

  Complex operator+(Complex const &obj)
  {
      Complex res;
      res.real=real+obj.real;
      res.img= img+obj.img;

      return res;
  }
   void print() { cout << real << " + i" << img << endl; }
};

int main()
{
    Complex c1(2,3);
    Complex c2(4,5);

    Complex c3=c1+c2;


    c3.print();
}  