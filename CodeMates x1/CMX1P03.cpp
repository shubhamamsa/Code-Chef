#include<bits/stdc++.h>
#define mod 998244353

using namespace std;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res%mod;
}

long long divide(long long a, long long b)	{
	return (a%mod*binpow(b, mod-2)%mod)%mod;
}


long long binomialCoeff(long long n, long long k) 
{ 
    long long res = 1; 
  
    // Since C(n, k) = C(n, n-k) 
    if (k > n - k) 
        k = n - k; 
  
    // Calculate value of 
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1] 
    for (long long i = 0; i < k; ++i) { 
        res = (res%mod*(n - i)%mod)%mod; 
        res = divide(res, (i + 1)); 
    } 
  
    return res; 
} 

void subMain()	{
	string s;
	cin >> s;
	long long counts[26] = {0};
	for(long long i=0;i<s.length();i++)
		counts[s[i]-'a']++;
	long long N;
	cin >> N;
	string name;
	string winner = "";
	long long score = 1, maxscore = 0;
	while(N--)	{
		score = 1;
		cin >> name;
		long long countn[26] = {0};
		for(long long i=0;i<name.length();i++)
			countn[name[i]-'a']++;
		for(long long i=0;i<26;i++)
			if(countn[i] != 0)	{
				if(counts[i] < countn[i])	{
					score = 0;
					break;
				}
				score=(score%mod*binomialCoeff(counts[i], countn[i])%mod)%mod;
			}
		if(score > 0 && score > maxscore)	{
			maxscore = score;
			winner = name;
		}
		cout << score << "\n";
	}
	if(winner == "")
		cout << "No Research This Month" << "\n";
	else
		cout << winner << "\n";
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