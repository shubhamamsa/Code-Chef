#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

void dfs(vector<int>tree[], int visited[], int root, int final_ans[], int cp)	{
	final_ans[root] = cp;
	if(cp == 1)
		cp = 2;
	else
		cp = 1;
	visited[root] = 1;
	for(int i=0;i<tree[root].size();i++)	{
		if(!visited[tree[root][i]])	{
			dfs(tree, visited, tree[root][i], final_ans, cp);
		}
	}
}

void subMain()	{
	int n;
	cin >> n;
	vector<int>tree[n+1];
	int u, v;
	for(int i=0;i<n-1;i++)	{
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	int visited[n+1] = {0}, final_ans[n+1] = {0};
	dfs(tree, visited, 1, final_ans, 1);
	for(int i=1;i<=n;i++)
		cout << final_ans[i] << " ";
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