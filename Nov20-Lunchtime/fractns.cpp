#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;


void find(int x, set<int>div[], int n)	{
	for(int i=1;i<=sqrt(x);i++)
		if(x%i==0)	{
			if(i+x <= n)
				div[x].insert(i);
			if(x/i+x <=n)
				div[x].insert(x/i);
		}
}

void subMain()	{
	int n;
	cin >> n;
	set<int>div[n+2];
	long long count = 0, count1=0;
	for(int i=1;i<=n+1;i++)	{
		find(i, div, n);
	}
	for(int i=1;i<=n;i++)	{
		cout << div[i].size();
		count+=div[i].size()+div[i+1].size()-1;
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