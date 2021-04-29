#include<bits/stdc++.h>
#define mod 2

using namespace std;

long long M(long long n, long long k)	{
	if(n == 1)
		return 1;
	if(k == 0)
		return 1;
	if(k == 1)
		return n-1;
	long long sum = 0;
	for(int i=0;i<=k;i++)	{
		sum+=M(n-1, k-i);
	}
	return sum;
}

void subMain()	{
	long long n, k;
	cin >> n >> k;
	cout << M(n, k);
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