#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

void subMain()	{
	long long n;
	cin >> n;
	long long a[n];
	long long sum = 0;
	for(long long i=0;i<n;i++)	{
		cin >> a[i];
		if(a[i] > 0)
			sum+=a[i];
	}
	vector<int>index;
	long long l = 0, r = n-1;
	while(l<r)	{
		while(l<r)	{
			if(a[l] < 0)
				break;
			l++;
		}
		while(l < r)	{
			if(a[r] > 0)
				break;
			r--;
		}
		if(l < r)	{
			index.push_back(l+1);
			index.push_back(r+1);
			l++;
			r--;
		}
	}
	cout << sum << endl;
	cout << index.size() << " ";
	sort(index.begin(), index.end());
	for(int i=0;i<index.size();i++)
		cout << index[i] << " ";
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