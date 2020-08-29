#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

void subMain()	{
	int n;
	cin >> n;
	int a[11] = {0}, x;
	for(int i=0;i<n;i++)	{
		cin >> x;
		a[x]++;
	}
	map<int, int>mode;
	int max = 0, maxi = 0;
	for(int i=1;i<=10;i++)	{
		if(a[i]!=0)
		mode[a[i]]++;
	}
	for(auto i: mode)	{
		if(max < i.second)	{
			max = i.second;
			maxi = i.first;
		}
	}
	cout << maxi;
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