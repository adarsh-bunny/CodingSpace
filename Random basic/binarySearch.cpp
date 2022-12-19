#include <bits/stdc++.h>

using namespace std;
int main()
{
    int x;
    int arr[] = {2, 3, 4, 5, 6, 8, 9};
    int l = sizeof(arr) / sizeof(arr[0]);
    cout << l << endl;
    cout << "enter element to be search" << endl;
    cin >> x;

    int lower = 0;
    int higher = l - 1;

    int key = 0;
    while (lower <= higher)
    {
        int mid = (lower + higher) / 2;
        //  cout << " value of mid " << mid << endl;
        if (arr[mid] == x)
        {
            key = 1;
            cout << "element found @-" << mid << endl;
            return 1;
        }
        else if (arr[mid] < x)
        {

            lower = mid + 1;
            //cout << "else if" << lower << endl;
        }
        else
        {
            higher = mid - 1;
            //2cout << "else " << higher << endl;
        }
    }
    if (key == 0)
        cout << "element not found " << endl;
}
