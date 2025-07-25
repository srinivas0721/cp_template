#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n' 
#define INF = LLONG_MAX>>1
const int MOD = 1e9 +7;
vector<vector<int>>ans;
void generate(int ind,vector<int>&v,vector<int>temp,int &n){
    if(ind==n){
        ans.push_back(temp);
        return;
    }
    //Pick step
    temp.push_back(v[ind]);
    generate(ind+1,v,temp,n);    
    //bracktracking step 
    temp.pop_back();

    //no pick step
    generate(ind+1,v,temp,n);
}
signed main (){
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>temp;
    generate(0,arr,temp,n);
    for(auto i:ans){
        for(auto j:i){
        cout<<j<<" ";}
        cout<<endl;
    }
    
return 0;
}