#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

void subMain()	{
	long long n;
	cin >> n;
	pair<long long, long long>cf[n];
	for(int i=0;i<n;i++)	{
		cin >> cf[i].second;
	}
	for(int i=0;i<n;i++)	{
		cin >> cf[i].first;
	}
	sort(cf, cf+n);
	long long sum = 0, k = 0;
	long long ans = 0;
	while(sum < n)	{
		sum+=cf[k].second;
		ans+=cf[k].first*cf[k].second;
		//cars.insert(cf[k]);
		k++;
	}
	sum-=cf[k-1].second;
	ans = ans-(cf[k-1].second-(n-sum))*cf[k-1].first;
	cout << ans;
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