#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

long long power(long long a, long long b)	{
	if(b == 0)
		return 1;
	long long answer = power(a, b/2)%mod;
	answer = (answer*answer)%mod;
	if(b%2!=0)
		answer = (answer*a)%mod;
	return answer;
}
long long min(long long a, long long b)	{
	return a<b?a:b;
}
long long divide(long long a, long long b)	{
	return (a%mod*(power(b, mod-2)%mod))%mod;
}

long long comb(long long n, long long r)	{
	long long answer = 1;
	long long k = min(r, n-r);
	for(long long i=0;i<k;i++)	{
		answer = (answer%mod*(n-i)%mod)%mod;
		answer = divide(answer, i+1);
	}
	return answer%mod;
}

void subMain()	{
	long long n;
	cin >> n;
	long long a[n], ans;
	for(long long i=0;i<n;i++)
		cin >> a[i];
	long long max = 0, maxcount = 0;
	for(long long i=0;i<n;i++)
		if(max < a[i])
			max = a[i];
	for(long long i=0;i<n;i++)
		if(max == a[i])
			maxcount++;
	if(n == 1)	{
		cout << 2;
		return;
	}
	if(maxcount%2!=0)
		ans = power(2, n)%mod;
	else
		ans = power(2, n)%mod-((power(2, n-maxcount)%mod)*comb(maxcount, maxcount/2)%mod)%mod;
	if(ans < 0)
		ans = (ans+mod)%mod;
	cout << ans%mod;
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