#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

void subMain()	{
    long long n;
    cin >> n;
    long double h[n];
    for(int i=0;i<n;i++)
        cin >> h[i];
    long long max_val = 0;
    long double max_slope;
    for(int i=0;i<n-1;i++)  {
        max_slope = -1000000000;
        for(int j = i+1;j<n;j++)    {
            if(max_slope <= (h[j]-h[i])/double(j-i))    {
                if(max_val < j-i)
                    max_val = j-i;
                max_slope = (h[j]-h[i])/double(j-i);
            }
        }
    }
    cout << max_val;
}

int main() {
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