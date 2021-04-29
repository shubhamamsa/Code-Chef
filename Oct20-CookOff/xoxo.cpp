#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

void subMain()	{
	long long n, k, x;
	cin >> n >> k >> x;
	if(n > k)	{
		cout << "YES";
	}
	else {
		long long maxx = (n/2)*(n-n/2);
		if(k <= maxx)
			cout << "YES";
		else
			cout << "NO";
	}
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