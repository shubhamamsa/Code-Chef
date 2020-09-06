#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;



void equalDiv1(long long n)	{

	long long arr[n];
	if(n%2 == 0)	{
		int flag = -1;
		for(int i=0;i<n/2;i++)	{
			arr[i] = flag;
			flag*=-1;
		}
		if((n/2)%2!=0)	{
			arr[n/2] = flag;
			for(int i=n/2+1;i<n;i++)	{
				arr[i] = flag;
				flag*=-1;
			}
		}
		else	{
			flag*=-1;
			for(int i=n/2;i<n;i++)	{
				arr[i] = flag;
				flag*=-1;
			}
		}
	}
	else {
		arr[0] = -1;
		int flag = -1;
		for(int i=1;i<(n+1)/2;i++)	{
			arr[i] = flag;
			flag*=-1;
		}
		if(((n-1)/2)%2!=0)	{
			arr[(n+1)/2] = flag;
			for(int i=(n+1)/2+1;i<n;i++)	{
				arr[i] = flag;
				flag*=-1;
			}
		}
		else	{
			flag*=-1;
			for(int i=(n+1)/2;i<n;i++)	{
				arr[i] = flag;
				flag*=-1;
			}
		}
	}
	long long sum1 = 0, sum2 = 0;
	for(int i=0;i<n;i++)	{
		if(arr[i] == -1)	{
			sum1+=i+1;
			//cout << 0;
		}
		else	{
			sum2+=i+1;
			//cout << 1;
		}
	}
	cout << abs(sum1-sum2)<<endl;
	for(int i=0;i<n;i++)	{
		if(arr[i] == -1)	{
			//sum1+=i+1;
			cout << 0;
		}
		else	{
			//sum2+=i+1;
			cout << 1;
		}
	}
}
void equalDiv2(long long n)	{
long long arr[n];
	if(n%2 == 0)	{
		int flag = -1;
		for(int i=0;i<n/2;i++)	{
			arr[i] = flag;
			flag*=-1;
		}
		if((n/2)%2!=0)	{
			arr[n/2] = flag;
			for(int i=n/2+1;i<n;i++)	{
				arr[i] = flag;
				flag*=-1;
			}
		}
		else	{
			flag*=-1;
			for(int i=n/2;i<n;i++)	{
				arr[i] = flag;
				flag*=-1;
			}
		}
	}
	else {
		arr[0] = -1;
		int flag = -1;
		for(int i=1;i<(n+1)/2;i++)	{
			arr[i] = flag;
			flag*=-1;
		}
		if(((n-1)/2)%2!=0)	{
			arr[(n+1)/2] = flag;
			for(int i=(n+1)/2+1;i<n;i++)	{
				arr[i] = flag;
				flag*=-1;
			}
		}
		else	{
			flag*=-1;
			for(int i=(n+1)/2;i<n;i++)	{
				arr[i] = flag;
				flag*=-1;
			}
		}
	}
	long long sum1 = 0, sum2 = 0;
	for(int i=0;i<n;i++)	{
		if(arr[i] == -1)	{
			sum1+=pow(i+1, 2);
			//cout << 0;
		}
		else	{
			sum2+=pow(i+1, 2);
			//cout << 1;
		}
	}
	cout << abs(sum1-sum2)<<endl;
	for(int i=0;i<n;i++)	{
		if(arr[i] == -1)	{
			//sum1+=i+1;
			cout << 0;
		}
		else	{
			//sum2+=i+1;
			cout << 1;
		}
	}
}
void equalDiv3(long long n)	{
;	
}
void equalDiv4(long long n)	{
;	
}

void subMain(long long k)	{
	long long n;
	cin >> n;
	switch(k)	{
		case 1: equalDiv1(n);break;
		case 2: equalDiv2(n);break;
		case 3: equalDiv3(n);break;
		case 4: equalDiv4(n);break;
	}
}

int main()	{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long t = 1, k;
	cin >> k;
	cin >> t;
	while(t--)	{
		subMain(k);
		cout << "\n";
	}	
	return 0;
}