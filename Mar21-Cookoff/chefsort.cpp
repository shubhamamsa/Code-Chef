#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

void subMain()	{
    long long n;
    cin >> n;
    long long a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    int count = 0, eq = 0;
    for(int i=1;i<n;i++)    {
        if(a[i] < a[i-1])
            count++;
        else if(a[i] == a[i-1])
            eq++;
    }
    if(count > n/2) {
        cout << n-count-eq << "\n";
        cout << 3 << " " << n << " " << 1073741823;
        for(int i=1;i<n;i++)    {
            if(a[i] > a[i-1])
                cout << 2 << " " << i+1 << " " <<1073741823 << "\n";
        }
    }
    else {
        cout << count << "\n";
        for(int i=1;i<n;i++)    {
            if(a[i] < a[i-1])
                cout << 2 << " " << i+1 << " " <<1073741823 << "\n";
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