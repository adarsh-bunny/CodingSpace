#include<bits/stdc++.h>
#include "POLINOMIALCLASS.cpp"

using namespace std;

int main()
{
    Polynomial p1;
 p1.setCoefficient(0,1);
 p1.setCoefficient(1,10);
 p1.setCoefficient(2,20);
 p1.setCoefficient(3,30);
p1.print();

Polynomial p2;
p2.setCoefficient(4,40);
p2.print();
Polynomial p4;
p4=p1;
p4.print();
Polynomial p3=p4+p1;

p3.print();

}