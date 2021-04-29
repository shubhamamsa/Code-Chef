#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

void subMain()	{
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	set<int>diff;
	for(int i=0;i<n;i++)	{
		int max = a[i], smax = 0;
		for(int j=i+1;j<n;j++)	{
			if(a[j] > max)	{
				smax = max;
				max = a[j];
			}
			else if(a[j] > smax)	{
				smax = a[j];
			}
			diff.insert(max-smax);
		}
	}
	cout << diff.size();
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