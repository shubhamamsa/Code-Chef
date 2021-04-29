#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

bool compareInterval(pair<long long, long long> i1, pair<long long, long long> i2)	{
    return (abs(i1.first) < abs(i2.first));
}

void subMain()	{
	long long n;
	cin >> n;
	long long m, x;
	vector<pair<long long, long long> >ants;
	long long sign[n][2];
	for(long long i=0;i<n;i++)	{
		sign[i][0] = sign[i][1] = 0;
	}
	map<long long, long long>pos[n];
	set<long long>first;
	set<long long>repeat;
	for(long long i=0;i<n;i++)	{
		cin >> m;
		for(long long j = 0;j<m;j++)	{
			cin >> x;
			ants.push_back(make_pair(x, i));
			if(first.find(abs(x)) == first.end())
				first.insert(abs(x));
			else
				repeat.insert(abs(x));
			if(x < 0)	{
				sign[i][0]++;
				pos[i][x] = j;
			}
			else	{
				sign[i][1]++;
				pos[i][x] = m-j-1;
			}
		}
	}
	sort(ants.begin(), ants.end(), compareInterval);
	long long total = repeat.size();
	for(long long i=0;i<ants.size();i++)	{
		//cout << ants[i].first << " " << ants[i].second << "\n";
		if(repeat.find(abs(ants[i].first)) != repeat.end())	{
			total += pos[ants[i].second][ants[i].first];
			// cout << pos[ants[i].second][ants[i].first] << endl;
		}
		else	{
			if(ants[i].first < 0)	{
				total += sign[ants[i].second][1];
			}
			else	{
				total += sign[ants[i].second][0];
			}
		}
		if(ants[i].first < 0)	{
			sign[ants[i].second][0]--;
		}
		else	{
			sign[ants[i].second][1]--;
		}
		// cout << total << endl;
	}
	cout << total;
	// for(int i=0;i<n;i++)	{
	// 	cout << sign[i][0] << " " << sign[i][1];
	// }
	// for(int i=0;i<n;i++)	{
	// 	for(auto k: pos[i])	{
	// 		cout << k.first << " " << k.second << endl;
	// 	}
	// }
	// for(auto i: repeat)	{
	// 	cout << i << " ";
	// }
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