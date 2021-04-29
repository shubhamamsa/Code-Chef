#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

void subMain()	{
	int n, d;
	cin >> n >> d;
	int a[n][d];
	for(int i=0;i<n;i++)	{
		for(int j=0;j<d;j++)
			cin >> a[i][j];
	}
	vector<pair<int, int> >weights;
	int max = 0, maxi;
	for(int i=0;i<n;i++)	{
		max = 0;
		for(int j=0;j<n;j++)	{
			if(i!=j)	{
				int calc = 0;
				for(int k=0;k<d;k++)	{
					calc+=abs(a[i][k]-a[j][k]);
				}
				if(max < calc)	{
					if(weights[j].second == i)
						continue;
					max = calc;
					maxi = j;
				}
			}
		}
		weights.push_back(make_pair(max, maxi));
	}
	sort(weights.begin(), weights.end());
	int sum = 0;
	for(int i=1;i<weights.size();i++)
		sum+=weights[i].first;
	cout << sum;
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