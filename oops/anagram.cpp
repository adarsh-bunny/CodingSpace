#include <bits/stdc++.h>
using namespace std;


bool areAnagram(string str1, string str2)
{
	
	int n1 = str1.length();
	int n2 = str2.length();


	if (n1 != n2)
		return false;
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());


	for (int i = 0; i < n1; i++)
		if (str1[i] != str2[i])
			return false;

	return true;
}

// Driver code
int main()
{
    string s1,s2;
	cin<<st1<<s2;
   transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
   cout<<areAnagram(s1, s2)<<endl;


	return 0;
}
