#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

void subMain()	{
	int n;
	cin >> n;
	int a[n];
	int sum = 0, x;
	for(int i=0;i<n;i++)	{
		cin >> x;
		a[i] = x;
		sum = (sum^x);
	}	
	cout << sum << endl;
	int k;
	cin >> k;
	int sum1 = 0;
	for(int i=0;i<n;i++)	{
		sum1+=(a[i]^k);
	}
	cout << sum1 << endl;
}

int main()	{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	//cin >> t;
	while(t--)	{
		subMain();
		cout << "\n";
	}	
	return 0;
}