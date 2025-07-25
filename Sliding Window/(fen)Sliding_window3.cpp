//CSES Sliding Median
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define INF LLONG_MAX>>1
const int MOD = 1e9 +7;

struct FenwickTreeOneBasedIndexing {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTreeOneBasedIndexing(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    };

    FenwickTreeOneBasedIndexing(vector<int> a)
        : FenwickTreeOneBasedIndexing(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    };

    int sum(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    };

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    };

    void add(int idx, int delta) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    };
};
FenwickTreeOneBasedIndexing fen(2e5);

map<int,int>compressed,decompressed;
void compression(vector<int>v){
    sort(v.begin(),v.end());
    map<int,int>mp;
    int cnt =1;
    for(auto num:v){
        if(!mp[num]){
            compressed[num]=cnt;
            decompressed[cnt]=num;
            cnt++;
        }
        mp[num]++;
    }
}
int givemid(int k){
    int l=1,r = 2e5;
    int ans;
    while(l<=r){
        int mid = (l+r)/2;
        int cnt = fen.sum(mid);
        if(cnt>=k){
            ans = mid;
            r = mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    multiset<int>mp;
    vector<int>v(n,0);
    for(int i =0;i<n;i++){
        cin>>v[i];
    }
    if(k==1){
        for(int i =0;i<n;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return 0;
    }
    compression(v);
    vector<int>ans;
    for(int i=0;i<k;i++){
        fen.add(compressed[v[i]],+1);
    }
    ans.push_back(decompressed[givemid((k+1)/2)]);
    for(int i =k;i<n;i++){
        fen.add(compressed[v[i-k]],-1);
        fen.add(compressed[v[i]],+1);
        ans.push_back(decompressed[givemid((k+1)/2)]);
    }
    for(auto num:ans){
        cout<<num<<" ";
    }
    cout<<endl;
}