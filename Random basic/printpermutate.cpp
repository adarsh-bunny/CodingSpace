#include<bits/stdc++.h>
using namespace std; 
 
void printPermutations(string input, string output){ 
  if(input.length() == 0){
        cout << output << endl; 
        return;
    }
    for(int i = 0; i<= output.length(); i++){
         cout<<" i = "<<i<<" "<<input.substr(1)<<" pass "<<output.substr(0,i) + input[0] + output.substr(i)<<" ol "<<output.length()<<endl;
        printPermutations(input.substr(1), output.substr(0,i) + input[0] + output.substr(i));
    }
    return;
}

int main(){
    string str="abc";
    int l=str.length();
    //cout<<l<<endl;
    int n=pow(l,2);
    //string *output= new string[n];
  string output ="";

printPermutations(str, output);
    return 0;
}