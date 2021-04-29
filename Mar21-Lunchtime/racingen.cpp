#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

void subMain()	{
    long long x, r, m;
    cin >> x >> r >> m;
    r *= 60;
    m *= 60;
    if(m < r)   {
        cout << "NO";
    }
    else    {
        if(x >= r)  {
            cout << "YES";
        }
        else    {
            r -= x;
            m -= x;
            if(2*r <= m)    {
                cout << "YES";
            }
            else
                cout << "NO";
        }
    }
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