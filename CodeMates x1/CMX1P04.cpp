#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

#include <bits/stdc++.h> 
using namespace std; 
   
const long long N = 1000000;  
  
long long n; 
 
long long tree[2 * N]; 
   
void build(long long arr[])  
{  
 
    for (long long i=0; i<n; i++)     
        tree[n+i] = arr[i];  
    for (long long i = n - 1; i > 0; --i)      
        tree[i] = tree[i<<1] + tree[i<<1 | 1];     
} 
 
void updateTreeNode(long long p, long long value)  
{  
    // set value at position p 
    tree[p+n] = value; 
    p = p+n; 
       
    for (long long i=p; i > 1; i >>= 1) 
        tree[i>>1] = tree[i] + tree[i^1]; 
} 
   
long long query(long long l, long long r)  
{  
    long long res = 0; 
      
    // loop to find the sum in the range 
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) 
    { 
        if (l&1)  
            res += tree[l++]; 
      
        if (r&1)  
            res += tree[--r]; 
    } 
      
    return res; 
} 

void subMain()	{
	cin >> n;
	long long a[n];
	for(long long i=0;i<n;i++)
		cin >> a[i];
	if(n == 1)	{
		int q;
		cin >> q;
		string s;
		int l, r;
		while(q--)	{
			cin >> s >> l >> r;
			if(s == "past")
				a[0]+=l;
			else
				cout << a[0] << endl;
		}
	}
	else	{
	build(a);
	long long Q;
	cin >> Q;
	string s;
	long long l, r;
	while(Q--)	{
		cin >> s >> l >> r;
		if(s == "past")	{
			updateTreeNode(r-1, l+a[r-1]);
			a[r-1]+=l;
		}
		else	{
			long long ans = query(l-1, r);
			cout << ans << "\n";
		}
	}
	}
}

int main()	{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	//cin >> t;
	while(t--)	{
		subMain();
		cout << "\n";
	}	
	return 0;
}