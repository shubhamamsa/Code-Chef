#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

void apply(int arr[], pair<int, int>rating[], pair<int, int>ranking[], int n, int m)	{
	pair<int, int>test[n];
	for(int i=0;i<n;i++)	{
		test[i].first = arr[i];
		test[i].second = i;
	}
	sort(test, test+n);
	int rank = 1;
	for(int i=n-1;i>=0;i--)	{
		if(i == n-1)	{
			if(rank < ranking[test[i].second].first)	{
				ranking[test[i].second].first = rank;
				ranking[test[i].second].second = m;
			}
		}
		else	{
			if(test[i].first != test[i+1].first)
				rank = n-i;
			if(rank < ranking[test[i].second].first)	{
				ranking[test[i].second].first = rank;
				ranking[test[i].second].second = m;
			}
		}
		if(rating[test[i].second].first < test[i].first)	{
			rating[test[i].second].first = test[i].first;
			rating[test[i].second].second = m;
		}
	}
}

void subMain()	{
	int n, m;
	cin >> n >> m;
	int x;
	int elo[m+1][n];
	pair<int, int>ratingMonth[n];
	pair<int, int>rankingMonth[n];
	for(int i=0;i<n;i++)	{
		ratingMonth[i].first = 0;
		ratingMonth[i].second = 0;
		rankingMonth[i].first = 1000;
		rankingMonth[i].second = 1000;
	}
	for(int i=0;i<n;i++)	{
		cin >> x;
		elo[0][i] = x;
	}
	for(int i=0;i<n;i++)
		for(int j=1;j<=m;j++)	{
			cin >> x;
			elo[j][i] = x+elo[j-1][i];
		}
	for(int i=1;i<=m;i++)	{
		apply(elo[i], ratingMonth, rankingMonth, n, i);
	}
	int count = 0;
	for(int i=0;i<n;i++)
		if(ratingMonth[i].second != rankingMonth[i].second)
			count++;
	cout << count;
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