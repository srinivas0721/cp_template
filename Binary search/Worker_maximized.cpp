#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n' 
#define INF LLONG_MAX>>1
const int MOD = 1e9 + 7;

/*Given an array of workload ,split it among k workers,such that 
maximum work any worker has to do is minimized*/ 
//Binary search
//let us consider the max val m = 40 starting from the first index
//we will keep continuing till the sum of work is <=40 then next 
//but max value iz 50 so we cant take give it to the worker 
//similarly the work less than 40 is also invalid 
// m is of range (l,r)
bool check(int m,vector<int>v,int k){
	int cnt =1;
	int sum =0;
	for(int i:v){
		if(sum +i>m){
			cnt++;
			sum =i;
		}
		else
			sum +=i;
	}
	return cnt<=k;
}
signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    
    int k =3;
    vector<int>v={10,5,20,50,25,45,15};
    int ans = -1;
    int l = *max_element(v.begin(),v.end());
    int r = accumulate(v.begin(),v.end(),0);
    while(l<=r){
    	int mid = (l+r)/2;
    	if(check(mid,v,k)){
    		ans = mid;
    		r = mid-1;
    	}
    	else
    		l = mid+1;
    }
    cout<<ans<<endl;
    return 0;
}