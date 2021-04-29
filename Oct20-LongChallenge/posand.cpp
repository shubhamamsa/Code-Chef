#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

void subMain()	{
	int n;
	cin >> n;
	if(n == 1)	{
		cout << 1;
		return;
	}
	if(!(n&(n-1)))	{
		cout << -1;
		return;
	}
	if(n == 3)	{
		cout << 1 << " " << 3 << " " << 2;
		return;
	}
	int a[n];
	for(int i=0;i<n;i++)
		a[i] = i+1;
	a[0] = 2;
	a[1] = 3;
	a[2] = 1;
	int p = 4;
	for(int i=3;i<n;i++)	{
		if(a[i]%p == 0)	{
			p*=2;
			swap(a[i], a[i+1]);
		}
	}
	for(int i=0;i<n;i++)
		cout << a[i] << " ";
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