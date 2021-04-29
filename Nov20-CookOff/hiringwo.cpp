#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
} 
  

long long findlcm(set<int>arr) 
{ 
    // Initialize result 
    long long ans = *arr.begin(); 
  
    // ans contains LCM of arr[0], ..arr[i] 
    // after i'th iteration, 
    for (auto i: arr) 
        ans = (((i * ans)) / 
                (gcd(i, ans))); 
  
    return ans; 
} 

bool prime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to n-1
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 
    return true;
}

int lcm(int a, int b) 
{ 
    return (a / __gcd(a, b) * b); 
} 

pair<int, int> find(int x) 
{ 
  
    int ans; 
  
    // To find the factors 
    for (int i = 1; i <= sqrt(x); i++) { 
  
        // To check if i is a factor of x and 
        // the minimum possible number 
        // satisfying the given conditions 
        if (x % i == 0 && lcm(i, x / i) == x) { 
  
            ans = i; 
        } 
    } 
  return make_pair(ans, (x / ans)); 
} 

bool psqr(int x)	{
	pair<int,int>tempo = find(x);
	if(tempo.first == 1 || tempo.second == 1)
		return true;
	return false;
}

void subMain()	{
	int k, x;
	cin >> k >> x;
	set<int>mp;
	pair<int, int>temp = find(x);
	mp.insert(temp.first);
	mp.insert(temp.second);
	int nums = 2, ones = 0;	
	//cout << temp.first << " " << temp.second << endl;
	while(nums<k)	{
		int diff, maxdiff = -1, num;
		for(auto i: mp)	{
			pair<int, int>temp = find(i);
			diff = i-(temp.first+temp.second);
			if(diff >= maxdiff)	{
				maxdiff = diff;
				num = i;
			}
		}
		mp.erase(num);
		pair<int, int>temp = find(num);
		mp.insert(temp.first);
		mp.insert(temp.second);
		if(maxdiff == -1)
			ones++;
		nums++;
	}
	int sum=0;
	for(auto i: mp)	{
		//cout << i << " ";
		sum+=i;
	}
	if(ones > 0)
	    ones--;
	cout << sum+(k-nums)+ones;;
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