#include <bits/stdc++.h>
using namespace std;
int lcs(string s, string t)
{
    // base casde
    if (s.size() == 0 || t.size() == 0)
        return 0;

    // calculation part

    if (s[0] == t[0])
        return 1 + lcs(s.substr(1), t.substr(1));
    else
    {
        int a = lcs(s.substr(1), t);
        int b = lcs(s, t.substr(1));
        //  int c=lcs(s.substr(1),t.substr(1));  // optional call

        // int ans=max(a,max(b,c)) ;
        int ans = max(a, b);
        return ans;
    }
}
int lcs_mem(string s, string t, int **output)
{
    int m = s.size();
    int n = t.size();
    // base casde
    if (s.size() == 0 || t.size() == 0)
        return 0;
    

    if(output[m][n]!=-1)
{
    return output[m][n];
}
    // calculation part

    int ans;
    if (s[0] == t[0])
        ans = 1 + lcs_mem(s.substr(1), t.substr(1), output);
    else
    {
        int a = lcs_mem(s.substr(1), t, output);
        int b = lcs_mem(s, t.substr(1), output);
        int c = lcs_mem(s.substr(1), t.substr(1), output); // optional call

        ans = max(a, max(b, c));
        // int ans=max(a,b) ;
    }

    output[m][n] = ans;

    return output[m][n];
}


int lcs_dp(string s, string t)
{
    int m = s.size();
    int n = t.size();
    // // base casde
    // if (s.size() == 0 || t.size() == 0)
    //     return 0;

int **output= new int*[m+1];
 for(int i=0;i<=m;i++)
 {
    output[i]= new int[n+1];
 }
// fill 1st row
  for(int i=0;i<=n;i++)
      output[0][i]=0;
  
// fill 1st col
 for(int j=1;j<=m;j++)
      output[j][0]=0;
  
  for(int i=1;i<=m;i++)
  {
      for(int j=1;j<=n;j++)
      {
          //check 1st character 
          if(s[m-i]==t[n-j])   //important observation
          {
              output[i][j]=1+output[i-1][j-1];
          }
          else{
              int a=output[i-1][j];
               int b=output[i][j-1];
               int c=output[i-1][j-1];
              output[i][j]= max(a,max(b,c));
          }
          
      }
  }

return output[m][n];
}
int main()
{
    string s, t;
    cin >> s >> t;
    cout << "Brute force " << lcs(s, t) << endl;
    int **output = new int *[s.size() + 1];
    for (int i = 0; i <= s.size(); i++)
    {
        output[i] = new int[t.size() + 1];
        for (int j = 0; j <= t.size(); j++)
            output[i][j] = -1;
    }
    cout << "Memoriztion method " << lcs_mem(s, t, output) << endl;
    cout << "DP method " << lcs_dp(s, t) << endl;
}