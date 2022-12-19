#include <bits/stdc++.h>

using namespace std;
struct Item
{
    int wt;
    int val;

  /*  Item(int w, int v)
    {
        wt = w;
        val = v;
    }*/
} pool[50];

bool comp(const struct Item &a, const struct Item &b)
{
    double r1 = (double)a.val / (double)a.wt;
    double r2 = (double)b.val / (double)b.wt;
    return r1 > r2;
}


int knapsack(struct Item *pool,int n,int w )
{
    double maxVal=0;
    int curr_w=w;

    for(int i=0;i<n;i++)
    {
        if(curr_w>=pool[i].wt)
        {
            curr_w-=pool[i].wt;
            maxVal+=pool[i].val;
        }
        else
        {
            maxVal+=pool[i].val*((double)curr_w/(double)pool[i].wt);
            break;
        }
    }

    return maxVal;
}
int main()
{
    int n, w;
    cin >> n >> w;

    //int ti[n];
    int xi[n], yi[n];
  
    for (int j = 0; j < n; j++)
    {
        cin >> pool[j].wt>>pool[j].val;
    }
   
    sort(pool, pool + n, comp);
    cout<<"knapsack max value "<<knapsack(pool,n,w)<<endl;
    for (int j = 0; j < n; j++)
    {

        cout << pool[j].wt << " val=" << pool[j].val<<endl;
    }
}

//3 50
//10 60 20 100 30 120