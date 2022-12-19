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
            cout<<"j value="<<j<<" i ="<<i<<" small size "<<smallSize<<" len "<<smallOutput[i]<<" smallOutput "<<smallOutput[i].length()<<endl;
            output[k] = smallOutput[i].substr(0,j) + input[0] + smallOutput[i].substr(j);
            cout<<output[k]<<" "<<smallOutput[i]<<endl;
            k++;
        }
    }
    return k;
}
// int returnPermutations(string input, string output[]){
// 	if(input.size()==1)
//     {
//         output[0]=input[0];
//         return 1;
        
//     }
//     int index=0;
//     for(int i=0 ;i< input.size();i++)
//     {
//         string smalloutput[1000];
//         cout<<" i = "<<i<<" "<<smalloutput[i]<<" pass "<<input.substr(0,i)+input.substr(i+1,input.size()-i-1)<<" so= "<<smalloutput<<endl;
//         int ans= returnPermutations(input.substr(0,i)+input.substr(i+1,input.size()-i-1),smalloutput);
//         for(int j=0;j<ans;j++)
//         {
//             output[index++]=input[i]+smalloutput[j];
//             cout<<" j = "<<j<<" "<<output[i]<<" index "<<index<<endl;
            
//         }
//     }
// return index;

//}
int main(){
    string str="abc";
    int l=str.length();
    //cout<<l<<endl;
    int n=pow(l,2);
    //string *output= new string[n];
//  string output ="";
//     returnPermutations(str,output);
 string output[10000];
    int count = returnPermutations(str, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}