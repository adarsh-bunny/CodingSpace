#include<bits/stdc++.h>
using namespace std;
#include "student.cpp"

 int main(){
     student s1;
     s1.age=12;
     s1.rollno=2;
     student *s6= new student;
     (*s6).age=13;
     s6->rollno=3;
     cout<<s1.age<<" age & "<<"rollno"<< s1.rollno<<endl;
     cout<<(*s6).age<<" age & "<<"rollno"<< s6->rollno;
 }