#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

void subMain()	{
	int n, m, k;
	cin >> n >> m >> k;
	int count = 0;
	for(int i=0;i<n;i++)	{
		int x, sum=0;
		for(int j=0;j<k;j++)	{
			cin >> x;
			sum+=x;
		}
		cin >> x;
		if(sum >= m && x<=10)
			count++;
	}
	cout << count;
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