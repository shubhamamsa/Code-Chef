#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

set<int>rootNode, visited;

void dfs(vector<int>tree[], int n)	{
	visited.insert(n);
	for(int i=0;i<tree[n].size();i++)	{
		if(visited.find(tree[n][i]) == visited.end())
			dfs(tree, tree[n][i]);
		else	{
			if(rootNode.find(tree[n][i]) != rootNode.end())	{
				rootNode.erase(tree[n][i]);
				return;
			}
		}
	}
}

void subMain()	{
	rootNode.clear();
	visited.clear();
	int n;
	cin >> n;
	vector<int>tree[n+1];
	int u, v;
	int count = 0;
	for(int i=0;i<n-1;i++)	{
		cin >> u >> v;
		tree[v].push_back(u);
	}
	for(int i=1;i<=n;i++)	{
		if(tree[i].size() == 0)	{
			count++;
		}
	}
	cout << count-1;
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