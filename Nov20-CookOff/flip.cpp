#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

void subMain()	{
	string a, b;
	cin >> a >> b;
	int n=a.length(), count=0, opp=0;
	for(int i=0;i<n;i++)
		if(a[i]!=b[i])
			opp++;
	for(int i=0;i<n;i++)	{
		if(opp == 0)
			break;
		int flag = 0;
		for(int j=i;j<n;j+=2)	{
			if(a[j] == b[j])
				break;
			if(a[j] == '0')
				a[j] = '1';
			else
				a[j] = '0';
			opp--;
			flag = 1;
		}
		if(flag)
		count++;
	}
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