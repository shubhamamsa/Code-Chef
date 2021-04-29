#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

void dfs(vector<long long>tree[], long long x, vector<long long>&weights, long long w[])	{
	weights.push_back(w[x]);
	if(tree[x].size()!=0)
		dfs(tree, tree[x][0], weights, w);
}

void subMain()	{
	long long n, q;
	cin >> n >> q;
	long long w[n+1];
	for(long long i=1;i<=n;i++)
		cin >> w[i];
	vector<long long>tree[n+1];
	long long u, v;
	for(long long i=0;i<n-1;i++)	{
		cin >> u >> v;
		tree[v].push_back(u);
	}
	vector<long long>firstChild, secondChild;
	for(long long i=0;i<q;i++)	{
		cin >> u >> v;
		dfs(tree, u, firstChild, w);
		dfs(tree, v, secondChild, w);
		long long sum = 0;
		for(int i=0;i<firstChild.size();i++)
			sum+=((firstChild[i]*secondChild[i])%(1l<<32));
		cout << sum << "\n";
		firstChild.clear();
		secondChild.clear();
	}
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