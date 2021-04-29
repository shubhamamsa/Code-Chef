#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

void subMain()	{
    long long  r, c, x;
    cin >> r >> c >> x;
    long long  a[r][c];
    long long  b[r][c];
    for(long long  i=0;i<r;i++)
        for(long long  j=0;j<c;j++)
            cin >> a[i][j];
    for(long long  i=0;i<r;i++)
        for(long long  j=0;j<c;j++)
            cin >> b[i][j];
    
    for(long long  i=0;i<r;i++)  {
        long long  j = 0, temp = 0;
        for(j=0;j+x-1<c;j++)  {
            temp += a[i][j]-temp-b[i][j];
            // cout << a[i][j] << ' ' << b[i][j] << ' ' << temp << endl;
            
            a[i][j] = b[i][j];
        }
        for(long long  k = j;k<j+x-1;k++)    {
            // cout << i << ' ' << k << endl;
                a[i][k] -= temp;
            }
    }

    for(long long  i=0;i<c;i++)  {
        long long  j = 0, temp = 0;
        for(j=0;j+x-1<r;j++)  {
            temp += ((a[j][i]-temp)-b[j][i]);
            a[j][i] = b[j][i];
        }
        for(long long  k = j;k<j+x-1;k++)    {
                a[k][i] -= temp;
            }
    }
    for(long long  i=0;i<r;i++)    {
        for(long long  j=0;j<c;j++)
            if(a[i][j] != b[i][j])  {
                cout << "No";
                return;
            }
    }
    cout << "Yes";
    
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