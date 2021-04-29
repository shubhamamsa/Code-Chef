#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

int findMin(int arr[], int n)
{
    // Calculate sum of all elements
    int sum = 0; 
    for (int i = 0; i < n; i++)
        sum += arr[i];
 
    // Create an array to store results of subproblems
    bool dp[n+1][sum+1];
 
    // Initialize first column as true. 0 sum is possible 
    // with all elements.
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
 
    // Initialize top row, except dp[0][0], as false. With
    // 0 elements, no other sum except 0 is possible
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;
 
    // Fill the partition table in bottom up manner
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=sum; j++)
        {
            // If i'th element is excluded
            dp[i][j] = dp[i-1][j];
 
            // If i'th element is included
            if (arr[i-1] <= j)
                dp[i][j] |= dp[i-1][j-arr[i-1]];
        }
    }
  	// for(int i=0;i<=n;i++)	{
  	// 	for(int j=0;j<=sum;j++)
  	// 		cout << dp[i][j] << ' ';
  	// 	cout << "\n";
  	// }
    // Initialize difference of two sums. 
    int diff = INT_MAX;
     
    // Find the largest j such that dp[n][j]
    // is true where j loops from sum/2 t0 0
    for (int j=sum/2; j>=0; j--)
    {
        // Find the 
        if (dp[n][j] == true)
        {
            diff = sum-2*j;
            break;
        }
    }
    return diff;
}

void subMain()	{
	int n, k;
	cin >> n >> k;
	int a[n];
	map<int, int>count;
	for(int i=0;i<n;i++)	{
		cin >> a[i];
		count[a[i]]++;
	}
	sort(a, a+n, greater<int>());
	int test[n] = {0};
	int sum = 0, pos = 0, index = 0;
	while(index < n && sum < 2*k)	{
		sum+=a[index];
		test[pos++] = a[index++];
	}
	int mindiff = findMin(test, pos);
		if(sum - mindiff >= 2*k)	{
			cout << pos;
			return;
		}
	while(index < n)	{
		sum += a[index];
		test[pos++] = a[index++];
		int mindiff = findMin(test, pos);
		if(sum - mindiff >= 2*k)	{
			cout << pos;
			return;
		}
	}
	cout << -1;
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