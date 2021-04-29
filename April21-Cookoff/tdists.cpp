#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

void subMain()	{
    long long x, y;
    cin >> x >> y;
    long long temp = sqrtl(x+y);
    if(x+y != temp*temp)    {
        cout << "NO";
        return;
    }
    if(y%2!=0 || 2*(temp-1) > (x+y)/2)    {
        cout << "NO";
        return;
    }
    y/=2;
    vector<long long>count;
    long long sum = 0;
    for(long long i=temp-1;i>0;i-=2)    {
        count.push_back(i);
        sum+=i;
    }
    long long tempsum = sum;
    long long lust = 0;
    while(sum > y)  {
        sum-=count[count.size()-1];
        count.pop_back();
        lust++;
    }
    if(sum != y)    {
        cout << "NO";
        return;
    }
    long long limit = 0;
    limit = 2*lust;
    vector<pair<long long, long long>>edge;
    long long test = 1;
    for(long long i=0;i<temp-1;i++)
        edge.push_back({test++, test});
    cout << "YES\n";
    cout << temp << "\n";
    for(long long i=2;i<2+limit;i++) {
        edge[i].first = 2;
    }
    for(long long i=0;i<temp-1;i++)   {
        cout << edge[i].first << " " << edge[i].second;
        if(i != temp-2)
            cout << "\n";
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