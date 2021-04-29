#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

void subMain()	{
	string s;
	cin >> s;
	int count = 0, flag = 0;
	for(int i=0;i<s.length();i++)	{
		if(s[i] == '1')
			flag = 1;
		else if(s[i] == '0' && flag == 1)	{
			flag = 0;
			count++;
		}
	}
	if(s[s.length()-1] == '1')
		count++;
	cout << count;
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