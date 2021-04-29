#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

void subMain()	{
    int a, y, x;
    cin >> a >> y >> x;
    int curr_candles = 1;
    if(a >= y)   {
        cout << x*y;
    }
    else    {
        cout << a*x+1;
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