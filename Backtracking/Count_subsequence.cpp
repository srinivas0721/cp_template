// Count subsequences having sum s.

#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n' 
#define INF = LLONG_MAX>>1
const int MOD = 1e9 +7;
int cnt =0;
void generate(int ind,vector<int>&v,int &n,int target,int sum=0){
    if(ind==n){
        if(sum== target){
            cnt++;
        }
        return;
    }
    if(sum+v[ind]<=target){
    //Pick step
    generate(ind+1,v,n,target,sum+v[ind]);  }  
    //bracktracking step 
     generate(ind+1,v,n,target,sum);
    //no pick step
}
signed main (){
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    vector<int>temp;
    generate(0,arr,n,target);
    cout<<cnt<<endl;
    
return 0;
}