#include<bits/stdc++.h>
using namespace std;
int returnPermutations(string input, string output[]){ 
    if(input.length() == 0){
        output[0] = ""; 
        return 1;
    }
    string smallOutput[10000];
    int smallSize = returnPermutations(input.substr(1), smallOutput); 
    int k = 0;
    for(int i = 0; i < smallSize; i++){ 
        for(int j = 0; j <=smallOutput[i].length(); j++){ 
            output[k++] = smallOutput[i].substr(0,j) + input[0] + smallOutput[i].substr(j);
        }
    }
    return k;
}

int main(){
    string str="abc";
    int l=str.length();
    int n=pow(l,2);
    //string *output= new string[n];
//  string output ="";
//     returnPermutations(str,output);
 string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}