#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

void subMain()	{
	int n, h, x;
	cin >> n >> h >> x;
	int bab;
	for(int i=0;i<n;i++)	{
		cin >> bab;
		if(x+bab >= h)	{
			cout << "YES";
			return;
		}
	}
	cout << "NO";	
}

int main()	{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	// cin >> t;
	while(t--)	{
		subMain();
		cout << "\n";
	}	
	return 0;
}