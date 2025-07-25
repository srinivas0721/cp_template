#include <bits/stdc++.h>
using namespace std;
 
#define int long long
const int INF = LLONG_MAX>>1;
const int MOD = 1e9 +7;
int n;
map <int,int> previous;
int query(int index){
    if(previous.contains(index)){
        return previous[index];
    }
    if(index ==0||index ==n+1)
    return INF;
    
    cout<<"?"<<index<<endl;
    int value;
    cin>>value;
    return previous[index]=value;
}

signed main(){
    cin>>n;
    int l = 0,r=n+1;
    while(r-l>1){
        int mid = (l+r)/2;
        (query(mid-1)>query(mid)?l=mid:r=mid);
    }
    cout<<l<<endl;
return 0;
}