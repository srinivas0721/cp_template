#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define INF LLONG_MAX>>1
const int MOD = 1e9 +7;
vector<vector<bool>>v(7,vector<bool>(7,0));
int counts =0;
string s;
void grid(int ind,int i,int j){
    if(ind >= s.size()){
        if(i == 6 && j ==0){
            counts++;
        }
        return ;
    }
    v[i][j]=1;
    if(s[ind]=='?'||s[ind]=='U'){
        if(i-1>=0&&!v[i-1][j]){
            grid(ind+1,i-1,j);
        }
    }
    if(s[ind]=='?'||s[ind]=='D'){
        if(i+1<=6&&!v[i+1][j]){
            grid(ind+1,i+1,j);
        }
    }if(s[ind]=='?'||s[ind]=='R'){
        if(j+1<=6&&!v[i][j+1]){
            grid(ind+1,i,j+1);
        }
    }if(s[ind]=='?'||s[ind]=='L'){
        if(j-1>=0&&!v[i][j-1]){
            grid(ind+1,i,j-1);
        }
    }
    v[i][j]=0;
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(NULL);
    cin>>s;
    grid(0,0,0);
    cout<<counts<<endl;
    return 0;
}