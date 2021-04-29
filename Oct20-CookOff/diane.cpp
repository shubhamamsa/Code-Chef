#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

void subMain()	{
	long D;
	cin >> D;
	if(D<99999)	{
		cout << 2 << "\n";
		cout << D+1 << " " << D+2;
	}
	else	{
		long n = D/99999;
		vector<long>finalAns;
		for(int i=0;i<n;i++)
			finalAns.push_back(99999);
		finalAns.push_back(100000);
		if(D%99998!=0)	{
			finalAns.push_back(1);
			finalAns.push_back(D-n*99998+1);
			finalAns.push_back(D-n*99998+2);
		}
		cout << finalAns.size() << "\n";
		for(int i=0;i<finalAns.size();i++)	{
			cout << finalAns[i] << " ";
		}
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