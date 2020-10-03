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
	int t;
	cin>>t;
	while(t--){
	    long long n;
	    cin>>n;
	    long long ans=highestPowerof2(n);
	    if(ans==n){
	        cout<<"-1"<<endl;
	    }
	    else{
	        for(long long i=ans;i<=n;i++){
	            cout<<i<<" ";
	        }
	        //ans=ans-1;
	        if(n%2==0){
	            cout<<"2"<<" "<<"3"<<" "<<"1"<<" ";
	            long long k=3;
	            while(pow(2,k)<=ans){
	                
	                
	                for(long long i=pow(2,k)-1;i>=pow(2,k-1);i--){
	                    cout<<i<<" ";
	                }
	                
	               k++;
	            }
	             cout<<endl;
	        }
	        else{
	            cout<<"1"<<" ";
	            long long k=2;
	            while(pow(2,k)<=ans){
	                
	                
	                for(long long i=pow(2,k)-1;i>=pow(2,k-1);i--){
	                    cout<<i<<" ";
	                }
	                k++;
	            }
	            cout<<endl;
	        }
	       
	 
	    }
	}
	return 0;
}