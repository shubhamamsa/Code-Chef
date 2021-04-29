#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

vector<long long>primes;

void make_prime()	{
	primes.push_back(2);
	for(long long i=3;i<=2000000;i++)	{
		long long j = 0, flag = 0;
		while(primes[j]*primes[j] <= i)	{
			if(i%primes[j] == 0)	{
				flag = 1;
				break;
			}
			j++;
		}
		if(flag == 0)
			primes.push_back(i);
	}
}

void subMain()	{
	long long n;
	cin >> n;
	long long b[n];
	long long a[n];
	for(int i=0;i<n;i++)	{
		cin >> b[i];
		a[i] = 1;
	}
	long long k = 0;
	map<int, int>values;
	for(int i=0;i<n;i++)	{
		if(values.find(b[i]-1) == values.end())
			values[b[i]-1] = primes[k++];
	}
	for(int i=0;i<n;i++)
		a[i] = values[b[i]-1];
	for(int i=0;i<n;i++)
		cout << a[i] << " ";
}

int main()	{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	cin >> t;
	make_prime();
	while(t--)	{
		subMain();
		cout << "\n";
	}	
	return 0;
}