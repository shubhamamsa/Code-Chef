#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

void subMain()	{
	long long c;
	cin >> c;
	long long x = 1;
	while(x <= c)	x*=2;
	x/=2;
	cout << (x-1)*((x-1)^c);
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