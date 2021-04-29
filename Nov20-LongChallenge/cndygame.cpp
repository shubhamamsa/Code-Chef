#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

void subMain()	{
	long long n;
	cin >> n;
	long long a[n];
	for(long long i=0;i<n;i++)
		cin >> a[i];
	if(a[0] == 1)	{
		long long q, r;
		cin >> q;
		while(q--)	{
			cin >> r;
			long long temp = r/n;
			if((r == 1&&n!=1) || (r%n!=0 && r%n!=1))
				temp++;
			cout << temp%mod << "\n";
		}
	}
	else	{
		long long tempArr[n]={0};
		for(long long i=0;i<n-2;i++)	{
			if(a[i+1]!=1)	{
				if(a[i]%2==0)
					tempArr[i] = a[i];
				else
					tempArr[i] = (a[i]-1);
			}
			else	{
				if(a[i]%2!=0)
					tempArr[i] = a[i];
				else
					tempArr[i] = (a[i]-1);	
			}
		}
		if(n > 1)	{
			if(a[n-2]%2 != 0)
				tempArr[n-2] = (a[n-2]-1);
			else
				tempArr[n-2] = a[n-2];
		}
		if(a[n-1]%2==0)
			tempArr[n-1] = (a[n-1]-1);
		else
			tempArr[n-1] = a[n-1];
		long long q, r;
		for(long long i=1;i<n;i++)
			tempArr[i]+=tempArr[i-1];
		cin >> q;
		while(q--)	{
			cin >> r;
			long long sum = (((r/n)%mod)*(tempArr[n-1]%mod))%mod;
			if(r%n == 0)	{
				if(a[n-1]%2==0)
					sum++;
			}
			else	{
				if((r-1)%n>0)
					sum+=tempArr[(r-2)%n]%mod;
			r = (r-1)%n;
			if((r < n-1) && a[r] == 1 && a[r-1]%2==0)	{
				sum+=2;
			}
			else if((r < n-1) && a[r] == 1 && a[r-1]%2!=0);
			else
				sum+=a[r];
		}
			cout << sum%mod <<"\n";
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
		//cout << "\n";
	}	
	return 0;
}