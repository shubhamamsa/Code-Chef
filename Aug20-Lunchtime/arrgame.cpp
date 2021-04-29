#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

void subMain()	{
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	int count = 0,  maxcounte = 0, maxcounto = 0, counti = 0;
	vector<int>countinge;
	vector<int>countingo;
	for(int i=0;i<n;i++)	{
		if(a[i] == 0)
			count++;
		else{
			if(count!=0)	{
				if(count%2 == 0)
					countinge.push_back(count);
				else
					countingo.push_back(count);
			count = 0;
		}
		}
	}
	sort(countinge.begin(), countinge.end());
	sort(countingo.begin(), countingo.end());
	if(countingo.size() == 1 && countinge.size() == 0)
		cout << "Yes";
	else if(countingo.size() == 0)
		cout << "No";
	else if(countingo.size() == 1 && countinge.size()>0)	{
		if((countingo[0]+1)/2 > countinge[countinge.size()-1])
			cout << "Yes";
		else
			cout << "No";
	}
	else if(countingo.size()>1 && countinge.size() == 0)	{
	int maxo = countingo[countingo.size()-1];
		int maxi = countingo[countingo.size()-2];
		if((maxo+1)/2 > maxi)
			cout << "Yes";
		else 
			cout << "No";
	}
	else 	{
		int maxo = countingo[countingo.size()-1];
		int maxi = max(countingo[countingo.size()-2], countinge[countinge.size()-1]);
		if((maxo+1)/2 > maxi)
			cout << "Yes";
		else 
			cout << "No";
	}
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