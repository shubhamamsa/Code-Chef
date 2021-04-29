#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

void subMain()	{
	int n;
	cin >> n;
	int a[n], count = 0;
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(a, a+n);
	for(int i=0;i<n;i++)	{
		if(a[i] > i+1)	{
			cout << "Second";
			return;
		}
		count += i+1-a[i];
	}
	if(count%2 == 0)
		cout << "Second";
	else
		cout << "First";
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