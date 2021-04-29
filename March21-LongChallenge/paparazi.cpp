#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

void subMain()	{
    long long n;
    cin >> n;
    long double h[n];
    for(int i=0;i<n;i++)
        cin >> h[i];
    long double maxll = 1;
    pair<long long, long double>test[n-1];
    test[n-2] = make_pair(n-1, (h[n-1]-h[n-2]));
    for(int i=n-3;i>=0;i--) {
        long long temp = i+1;
        long double temp_slope = (h[temp]-h[i]);
        while(temp <= n-2 && temp_slope <= test[temp].second)    {
            temp_slope = (h[test[temp].first]-h[i])/(test[temp].first-i);
            temp = test[temp].first;
        }
        test[i] = make_pair(temp, temp_slope);
    }
    for(int i=0;i<n-1;i++)  {
        if(maxll < test[i].first-i+1)
            maxll = test[i].first-i;
        // cout << test[i].first << " " << test[i].second << endl;
    }
    cout << maxll;
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