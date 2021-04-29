#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

long long min(long long a, long long b)	{
	if(a < b)
		return a;
	return b;
}

void subMain()	{
	long long n, e, h, a, b, c;
	cin >> n >> e >> h >> a >> b >> c;
	long long mini = min(e, h);
	long long eggs = 0, choc = 0;
	long long cakes = 0, shake = 0, omelete = 0;
	cakes = mini;
	shake = (h-mini)/3;
	choc = (h-mini)%3;
	omelete = (e-mini)/2;
	eggs = (e-mini)%2;
	if(shake+cakes+omelete < n)	{
		cout << -1;
		return;
	}
	long long money = 0;
	if(c <= a && c <= b)	{
		long long count = min(n, cakes);
		money += count*c;
		n -= count;
		if(a <= b)	{
			count = min(n, omelete);
			money += count*a;
			n -= count;
			money+=n*b;
		}
		else	{
			count = min(n, shake);
			money += count*b;
			n -= count;
			money+=n*a;	
		}
	}
	else if(a <= b && a < c)	{
		// if(eggs == 1)	{
		// 	cakes--;
		// 	omelete++;
		// 	choc++;
		// }
		if(b <= c)	{
			long long cost = 1000000000000000;
			while(cakes >= 0)	{
				if(cakes+shake+omelete >= n)	{
					long long tempn = n;
					long long amount = 0;
					amount += min(tempn, omelete)*a;
					tempn-=min(tempn, omelete);
					amount += min(tempn, shake)*b;
					tempn-=min(tempn, shake);
					amount += tempn*c;
					if(amount < cost)
						cost = amount;
				}
					cakes--;
					eggs++;
					choc++;
					omelete += eggs/2;
					eggs = eggs%2;
					shake += choc/3;
					choc = choc%3;
			}
			money = cost;
		}
		else	{
			long long cost = 1000000000000000;
			while(cakes >= 0)	{
				if(cakes+shake+omelete >= n)	{
					long long tempn = n;
					long long amount = 0;
					amount += min(tempn, omelete)*a;
					tempn-=min(tempn, omelete);
					amount += min(tempn, cakes)*c;
					tempn-=min(tempn, cakes);
					amount += min(tempn, shake)*b;
					tempn-=min(tempn, shake);
					if(amount < cost)
						cost = amount;
				}
					cakes--;
					eggs++;
					choc++;
					omelete += eggs/2;
					eggs = eggs%2;
					shake += choc/3;
					choc = choc%3;
			}
			money = cost;
		}
	}	
	else if(b < a && b < c)	{
		// if(eggs == 1)	{
		// 	cakes--;
		// 	omelete++;
		// 	choc++;
		// }
		if(a <= c)	{
			long long cost = 1000000000000000;
			while(cakes >= 0)	{
				if(cakes+omelete+shake >= n)	{
					long long tempn = n;
					long long amount = 0;
					amount += min(tempn, shake)*b;
					tempn-=min(tempn, shake);
					amount += min(tempn, omelete)*a;
					tempn-=min(tempn, omelete);
					amount += min(tempn, cakes)*c;
					tempn-=min(tempn, cakes);
					if(amount < cost)
						cost = amount;
				}
					cakes--;
					eggs++;
					choc++;
					omelete += eggs/2;
					eggs = eggs%2;
					shake += choc/3;
					choc = choc%3;
			}
			money = cost;
		}
		else	{
			long long cost = 1000000000000000;
			while(cakes >= 0)	{
				if(cakes+omelete+shake >= n)	{
					long long tempn = n;
					long long amount = 0;
					amount += min(tempn, shake)*b;
					tempn-=min(tempn, shake);
					amount += min(tempn, cakes)*c;
					tempn-=min(tempn, cakes);
					amount += min(tempn, omelete)*a;
					tempn-=min(tempn, omelete);
					if(amount < cost)
						cost = amount;
				}
					cakes--;
					eggs++;
					choc++;
					omelete += eggs/2;
					eggs = eggs%2;
					shake += choc/3;
					choc = choc%3;
			}
			money = cost;
		}
	}

	cout << money;
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