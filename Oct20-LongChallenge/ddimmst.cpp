#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

long long abso(long long x)	{
	long long t = -1;
	if(x < 0)
		x*=t;
	return x;
}

long long mst(long long a[], long long n)	{
	vector<long long>test;
	for(int i=0;i<n;i++)	{
		for(int j=i+1;j<n;j++)
		test.push_back(abso(a[i]-a[j]));
	}
	sort(test.begin(), test.end(), greater<long long>());
	long long sum = 0;
	for(int i=0;i<n-1;i++)
		sum+=test[i];
	return sum;
}

void subMain()	{
	long long n, d;
	cin >> n >> d;
	long long a[d][n];
	for(long long i=0;i<n;i++)	{
		for(long long j=0;j<d;j++)
			cin >> a[j][i];
	}
	long long sum = 0;
	for(int i=0;i<d;i++)
		sum+=mst(a[i], n);
	cout << sum;
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