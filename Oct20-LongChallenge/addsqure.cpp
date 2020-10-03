#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

void subMain()	{
	int W, H, N, M;
	cin >> W >> H >> N >> M;
	int A[N], B[M];
	for(int i=0;i<N;i++)
		cin >> A[i];
	for(int i=0;i<M;i++)
		cin >> B[i];
	sort(A, A+N);
	sort(B, B+M);
	if(A[0] > B[0])	{
		int diff = A[0]-B[0];
		for(int i=0;i<N;i++)
			A[i]-=diff;
	}	
	else	{
		int diff = B[0]-A[0];
		for(int i=0;i<M;i++)
			B[i]-=diff;

	}
	set<int>points;
	for(int i=0;i<N;i++)
		points.insert(A[i]);
	int count = 0;
	vector<int>test;
	for(int i=0;i<M;i++)	{
		if(points.find(B[i])!=points.end())	{
			count++;
			test.push_back(B[i]);
			points.erase(B[i]);
		}
	}
	if((*points.begin())<=H)	{
		test.push_back((*points.begin()));
		count++;
	}
	set<int>salute;
	int acount = 0;
	for(int i=0;i<test.size();i++)	{
		for(int j=i+1;j<test.size();j++)	{
			if(salute.find(abs(test[i]-test[j])) == salute.end())	{
				acount++;
				salute.insert(abs(test[i]-test[j]));
			}
		}
	}
	cout << acount;
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