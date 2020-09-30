#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

void createObs(string ins)	{
	for(int i=1;i<=5;i++)	{
		for(int j=1;j<=5;j++)	{
			int u = 0, v = 0;
			for(int k=0;k<ins.length();k++)	{
				if(ins[k] == 'U')	{
					if(u != i || v+1 != j)
						v++;	
				}
				else if(ins[k] == 'R')	{
					if(u+1 != i || v != j)
						u++;	
				}
				else if(ins[k] == 'L')	{
					if(u-1 != i || v != j)
						u--;
				}
				else	{
					if(u != i || v-1 != j)
						v--;
				}
			}
		cout << u << " " << v << endl;
		}
	}
}

void subMain()	{
	int r, c;
	cin >> r >> c;
	createObs("URRRRRRULLLLLLURRRRRRULLLLLLURRRR");
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