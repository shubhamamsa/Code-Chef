#include<bits/stdc++.h>

#define mod 998244353

using namespace std;

long long power(long long a, long long b) {
    a %= mod;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

long long division(long long a, long long b)	{
	return (a%mod)*power(b, mod-2)%mod;
}

void subMain()	{
	long long  m, n, k;
	cin >> m >> n >> k;
	long long ev, ee, ef;
	ev = division(n*m, 1);
	ee = division(n*(m-1)+m*(n-1), k);
	if(m == 1)
		ef = 1;
	else
		ef = division((n-1), ((k*k)%mod*k)%mod)+1;
	cout << (ev - ee + ef -1+mod)%mod; 
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