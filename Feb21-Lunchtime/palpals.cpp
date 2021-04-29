#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

void subMain()	{
	string s;
	cin >> s;
	int a[26] = {0};
	for(int i=0;i<s.length();i++)
		a[s[i]-'a']++;
	int odd = 0, even = 0;
	for(int i=0;i<26;i++)	{
		if(a[i] > 0)	{
			if(a[i]%2 != 0)
				odd++;
			even += a[i]/2;
		}
	}
	if(even >= odd)
		cout << "YES";
	else
		cout << "NO";
}

int main()	{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	cin >> t;
	while(t--)	{
		subMain();
		cout << "\n";
	}	
	return 0;
}