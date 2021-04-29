#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

long long find(int a[], int n)  {
    long long sum = 0;
    for(int i=0;i<n;i++)    {
        if(a[i] > 0)
        sum += (1 << i);
    }
    return sum;
}

void subMain()	{
    long long n, q;
    cin >> n >> q;
    long long a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    int xorr[35] = {0};
    for(int i=0;i<n;i++)    {
        int temp = 0, tempo = a[i];
        while(tempo)    {
            int dig = (tempo&1);
            if(dig)
                xorr[temp]++;
            tempo = (tempo >> 1);
            temp++;
        }
    }
    cout << find(xorr, 35) << "\n";
    long long x, v;
    while(q--)  {
        cin >> x >> v;
        x--;
        int temp = 0, tempo = a[x];
        while(tempo)    {
            int dig = (tempo&1);
            if(dig)
                xorr[temp]--;
            tempo = (tempo >> 1);
            temp++;
        } 
        a[x] = v;
        temp = 0, tempo = a[x];
        while(tempo)    {
            int dig = (tempo&1);
            if(dig)
                xorr[temp]++;
            tempo = (tempo >> 1);
            temp++;
        } 
        cout << find(xorr, 35) << "\n";
    }
}

int main()	{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--)	{
        subMain();
    }
    return 0;
}