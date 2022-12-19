#include <iostream>
using namespace std;

int main() {
    int num,temp,res=0,r,fact=1,i=1;
    cout << "enter any number\n";
    cin >> num;
    
     temp=num;
     while(temp!=0) {
         r=temp%10;
         i=1,fact=1;
         while(i<=r) {
         fact=fact*i;
         i++;
         }
         cout<<"fact= "<<fact<<endl;
         res=res+fact;
         temp = temp/10;
     }
     
     if(res==num) {
         cout << " it is strong ";
     }
     else {
         cout << "it is not strong number";
     }
     return 0;
}