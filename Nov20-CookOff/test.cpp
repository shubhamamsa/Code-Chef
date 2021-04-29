#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

void subMain()	{
	map<int, int>test;
	test[10]++;
	test[11]++;
	auto i=test.end();
	i--;
	test[12]++;
	cout << i->first;	

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