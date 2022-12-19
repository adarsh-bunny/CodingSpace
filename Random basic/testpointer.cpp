#include <bits/stdc++.h>
using namespace std;

int main()
{
    int score{10};
    int *ptr = &score;
    cout << ptr << endl;
    char s[] = {"pallavi"};
    char *ptr2 = s;
    cout << ptr2 << endl;
    int *ptr3 = &s;
    cout << ptr3 << endl;
}