#include <iostream>
#include<bits/stdc++.h>
using namespace std;
long long highestPowerof2(long long n) 
{ 
    long long res = 0; 
    for (long long i=n; i>=1; i--) 
    { 
        // If i is a power of 2 
        if ((i & (i-1)) == 0) 
        { 
            res = i; 
            break; 
        } 
    } 
    return res; 
} 
int main() {
	// your code goes here
	for(int i = 1;i<=100000;i++)	{
		if((i*i+i)%100 == 0)
			cout << i << endl;
	}
	return 0;
}