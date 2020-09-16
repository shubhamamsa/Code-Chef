#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

unsigned long long power(unsigned long long a, unsigned long long b)	{
	if(b == 0)
		return 1;
	unsigned long long ans = power(a, b/2);
	ans = ans*ans;
	if(b%2!=0)
		ans = ans*a;
	return ans;
}

void equalDiv1(unsigned long long n)	{

	vector<int>check(n);
	vector<long long>arr(n);
	arr[0] = 1;
	for(long long i=2;i<=n;i++)
		arr[i-1] = arr[i-2]+power(i, 1);
	long long maxsum = arr[n-1];
	long long sum1 = 0, sum2 = 0, k=-1;
	for(long long i=0;i<n;i++)	{
		sum1=arr[i];
		sum2 = maxsum-sum1;
		if(sum1 > sum2)	{
			check[i] = 1;
			k = i-1;
			break;
		}
	}
	long long diff = sum1-sum2;
	for(long long i=k;i>=0;i--)	{
		if(sum1 > sum2)	{
			if((sum1-arr[i] >= sum2 + arr[i]) && (sum1-sum2-2*arr[i])<diff)	{
				check[i] = 1;
				sum1-=arr[i];
				sum2+=arr[i];
				diff = sum1-sum2;
				break;
			}
			else if((sum1-arr[i] < sum2 + arr[i]) && (sum2-sum1+2*arr[i])<diff)	{
				check[i] = 1;
				sum1-=arr[i];
				sum2+=arr[i];
				diff = sum2-sum1;	
			}
		}
		else	{
			if((sum2-arr[i] >= sum1 + arr[i]) && (sum2-sum1-2*arr[i])<diff)	{
				check[i] = 1;
				sum2-=arr[i];
				sum1+=arr[i];
				diff = sum2-sum1;
				break;
			}
			else if((sum2-arr[i] < sum1 + arr[i]) && (sum1-sum2+2*arr[i])<diff)	{
				check[i] = 1;
				sum1+=arr[i];
				sum2-=arr[i];
				diff = sum1-sum2;	
			}
		}
	}
	cout << diff;
	//cout << sum1 << " " << sum2 << endl;
	int flag = 1;
	vector<int>final(n);
	for(int i=0;i<n;i++);
		//cout << check[i];
	cout << endl;
	for(int i=0;i<n;i++)	{
		if(flag == 1)
			final[i] = 1;
		else
			final[i] = 0;
		if(check[i] == 1)
			flag*=-1;
	}
	sum1=0, sum2=0;
	for(int i=0;i<n;i++)	{
		if(final[i] == 1)
			sum1+=i+1;
		else
			sum2+=i+1;
		cout << final[i];
	}
}

void equalDiv2(unsigned long long n)	{
	vector<int>check(n);
	vector<unsigned long long>arr(n);
	arr[0] = 1;
	for(unsigned long long i=2;i<=n;i++)
		arr[i-1] = arr[i-2]+(i*i);
	unsigned long long maxsum = arr[n-1];
	unsigned long long sum1 = 0, sum2 = 0, k=-1;
	k = n-1;
	sum1 = maxsum;
	sum2 = 0;
	unsigned long long diff = sum1-sum2;
	for(int i=k;i>=0;i--)	{
		if(sum1 > sum2)	{
			if((sum1-arr[i] >= sum2 + arr[i]) && (sum1-sum2-2*arr[i])<=diff)	{
				check[i] = 1;
				sum1-=arr[i];
				sum2+=arr[i];
				diff = sum1-sum2;
				break;
			}
			else if((sum1-arr[i] < sum2 + arr[i]) && (sum2-sum1+2*arr[i])<=diff)	{
				check[i] = 1;
				sum1-=arr[i];
				sum2+=arr[i];
				diff = sum2-sum1;	
			}
		}
		else	{
			if((sum2-arr[i] >= sum1 + arr[i]) && (sum2-sum1-2*arr[i])<=diff)	{
				check[i] = 1;
				sum2-=arr[i];
				sum1+=arr[i];
				diff = sum2-sum1;
				break;
			}
			else if((sum2-arr[i] < sum1 + arr[i]) && (sum1-sum2+2*arr[i])<=diff)	{
				check[i] = 1;
				sum1+=arr[i];
				sum2-=arr[i];
				diff = sum1-sum2;	
			}
		}
	}
	cout << diff << endl;
	cout << sum1 << " " << sum2 << endl;
	int flag = 1;
	for(int i=0;i<n;i++)	{
		if(flag == 1)
			cout << 1;
		else
			cout << 0;
		if(check[i] == 1)
			flag*=-1;
	}
	cout << endl << endl;
}
void subMain(long long k)	{
	unsigned long long n;
	cin >> n;
	for(int i=1;i<=n;i++)	{
	switch(k)	{
		case 1: equalDiv1(n);break;
		case 2: equalDiv2(i);
				break;
		case 3: //equalDiv3(n);
				break;
		case 4: //equalDiv4(n);
				break;
	}
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