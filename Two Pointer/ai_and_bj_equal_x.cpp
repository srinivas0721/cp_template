#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n' 
#define INF LLONG_MAX>>1
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    


    int x = 5;
    vector<int>a{1,2,3,4,6};
    vector<int>b{-1,2,3,4,4};

    int n = a.size(),m=b.size();

    for(int i=0,j=m-1;i<n;i++){
    	int rem = x-a[i];

    	while(j>=0&&b[j]>rem){        //Learn why time complexity = o(n+m)
    		j--;
    	}

    	if(j>=0&&b[j]==rem){
    		cout<<i<<" "<<j<<endl; 
    	}
    }
    return 0;
}