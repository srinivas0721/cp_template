//Max Sum of the Subarray

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define INF LLONG_MAX>>1
const int MOD = 1e9 +7;

//(r-l+1) = size of the subarray r is the rightmost element of the subarray
signed main(){
    ios::sync_with_stdio(false);cin.tie(NULL);
    vector<int>v{1,3,5,2,7};
    int k = 2,sum=LLONG_MIN,ans=0;
    int n = v.size();
    for(int i =0;i<k;i++){
        ans += v[i];           // calculate 1st subarray sum first(1st window sum)
    }
    sum = max(ans,sum);
    for(int i =k;i<n;i++){
        int add_index = i;             //use another window to slide 1 window at a time
        int remove_index = i-k;        //for the next subarray it removes firsst element and adds element just after the given subarray
        ans = ans - v[remove_index]+ v[add_index];    
        //Sum of next window
        sum = max(sum,ans);
    }
    cout<<sum<<endl;
    return 0;
}