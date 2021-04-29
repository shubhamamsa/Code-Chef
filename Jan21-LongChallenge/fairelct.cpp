#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

void subMain()	{
	int n, m;
	cin >> n >> m;
	int a[n], b[m];
	int suma = 0, sumb = 0;
	for(int i=0;i<n;i++)	{
		cin >> a[i];
		suma+=a[i];
	}
	for(int i=0;i<m;i++)	{
		cin >> b[i];
		sumb+=b[i];
	}
	sort(a, a+n);
	sort(b, b+m);
	int i = 0, j = m-1, count = 0;
	while((a[i] < b[j]) && (suma <= sumb) && j>=0 && i<n)	{
		suma += b[j]-a[i];
		sumb -= b[j]-a[i];
		j--;
		i++;
		count++;
	}
	if(suma <= sumb)
		count = -1;
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