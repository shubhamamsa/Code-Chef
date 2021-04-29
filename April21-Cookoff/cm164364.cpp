#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

int max(int a, int b)   {
    if(a > b)
    return a;
    return b;
}

void subMain()	{
    int n, x;
    cin >> n >> x;
    int a;
    set<int>distinct;
    for(int i=0;i<n;i++)    {
        cin >> a;
        distinct.insert(a);
    }
    int temp = max(0, (x - (n - distinct.size())));
    cout << distinct.size()-temp;
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