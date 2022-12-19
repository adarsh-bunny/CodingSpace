#include <bits/stdc++.h>
using namespace std;

pair<int,int> longestConsecutiveSequence(int *arr, int n)
{
    unordered_map<int, bool> mp;
    unordered_map<int, int> index;
    for (int i = 0; i < n; i++) // special handle for duplicates
    {
        mp[arr[i]] = true;
        if (index.count(arr[i]) == 0)
            index[arr[i]] = i;
    }
    int maxLength = 0;
    int start = -1;

    for (int i = 0; i < n; i++)
    {
        if (mp[arr[i]] == false) // if already visted continue;
            continue;

        int nsize = 0, nstart = arr[i];
        int j = arr[i];

        while (mp.count(j) > 0 && mp[j] == true) //forward  (if present and not visited)
        {
            nsize += 1;
            mp[j] = false;
            j++;
        }

        j = arr[i] - 1;
        while (mp.count(j) > 0 && mp[j] == true) //forward  (if present and not visited)
        {
            nsize += 1;
            mp[j] = false;
        
            nstart--;
            j--;
        }
      //  cout<< nsize<<" " <<maxLength<<" "<<start<<" " << nstart<<endl;
        if (nsize >= maxLength) //update
        {
            if (maxLength == nsize) // the starting point comes first in input array.
            {
                if (index[start] > index[nstart])
                    start = nstart;
            
            }
            else
                 start =nstart;

            maxLength = nsize;
             
        }

    }
 //   cout<<maxLength<<" "<<start<<" " <<endl;
   
  pair<int,int> res;
    res.first=start;
    res.second=start+maxLength-1;
    return res;
}
int main()
{
    
    int arr[] = {2, 12, 9, 16, 10, 5, 3, 20, 25, 11, 1, 8, 6};
    int arr2[]={3, 7 ,2, 1, 9, 8, 41};
      int arr3[]={15, 24, 23, 12, 19, 11 ,16};       
    int n = 7 ;
    pair<int,int> res = longestConsecutiveSequence(arr3, n);
      cout<<res.first<<" "<<res.second<<" " <<endl;
    // for (int i = 0; i < res.size(); i++)
    // {
    //     cout << res[i] << " ";
    // }
}