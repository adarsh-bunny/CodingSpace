#include <bits/stdc++.h>
using namespace std;

void subset(int input[], int n, int output[], int l)
{

    if (n < 1)
    {
        output[0] = 0;
        return;
    }
    subset(input + 1, n - 1, output, l);
    for (int i = 0; i < l; i++)
    {
        cout << output[i] << " ";
    }
    subset(input + 1, n - 1, output, l + 1);
    output[l] = input[0];
    for (int i = 0; i < l; i++)
    {

        cout << output[i] << " ";
    }
    return;
}
// void print_subsets(int *arr, int index, int size)
// {
//     static vector<int> ans;

//     if (index == size)
//     {
//         cout << "{";
//         for (int i = 0; i < ans.size(); i++)
//         {
//             cout << ans[i];
//             if (i != ans.size() - 1)
//                 cout << ", ";
//         }
//         cout << "}" << endl;
//         return;
//     }
//     print_subsets(arr, index + 1, size);
//     ans.push_back(arr[index]);
//     print_subsets(arr, index + 1, size);
//     ans.pop_back();
// }
int main()
{
    int arr[] = {7, 8, 9};
    int l = sizeof(arr) / sizeof(arr[0]);
    cout << l << endl;
    int output[8];
    subset(arr, l, output, 0);
    //print_subsets(arr, 0, l);
}
