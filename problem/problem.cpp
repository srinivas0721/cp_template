
//     https://codeforces.com/problemset/problem/1343/C

#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n' 
#define INF = LLONG_MAX>>1
const int MOD = 1e9 +7;
 
signed main (){
ios::sync_with_stdio(false);cin.tie(NULL);
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    int arr[n];
    int neg=0,pos=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int count =0,sum=0,i=0;
    while(i<n){
        while(i<n&&arr[i]>0){
                count = max(count,arr[i]);
                i++;
        }
        sum+=count;
        if(i!=n){
        count=arr[i];
        while(i<n&&arr[i]<0){
                count  = max(arr[i],count);
                i++;
        }
        sum+=count;
        count=0;}
    }
    cout<<sum<<endl;
}
return 0;
}