#include <iostream>
using namespace std;
int main()
{
    char st[] = "ABCD";
    cout << *(st) << *(st) + 1 << " " << st << " " << st + 1 << endl;
    for (int i = 0; st[i] != '\0'; i++)
    {
        cout << st[i] << *(st) + i << *(i + st) << i[st];
    }
    return 0;
}
