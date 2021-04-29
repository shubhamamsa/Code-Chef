#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

void subMain()	{
	int n;
	cin >> n;
	int a[n], b[n];
	for(int i=0;i<n;i++)	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b+n, greater<int>());
	for(int i=0;i<n;i++)	{
		if(a[i] != b[i])	{
			cout << "Yes";
			return;
		}
	}
	cout << "No";
		
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