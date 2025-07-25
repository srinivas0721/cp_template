// In a path, no cell can be visited more than one time. 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n' 
#define INF = LLONG_MAX>>1
const int MOD = 1e9 +7;
int di[]={0,1,0,-1}; //[nothing,down,nothing,up]
int dj[]={1,0,-1,0}; //[right,nothing,left,nothing]
string dir= "RDLU";
bool isvalid(int i,int j,int n,int m,vector<vector<int>>&arr){
    if(i>=0&&j>=0&&i<n&&j<n&&arr[i][j]==0){
        return true;
    }
    return false;
}
void generate(int i,int j,int n,int m,vector<vector<int>>&arr,string &path){
    if(i==n-1&&j==n-1){
        cout<<path<<endl;
        return;
    }
    arr[i][j]=1;         //when i move to a certain block i will mark it as trap(1) then move forward 
    //right --> col. shift --> j to j+1
    //down --> row. shift --> i to i+1
    //same for up and down
    //int right = count(i,j+1,n,m,arr);
    //int down = count(i+1,j,n,m,arr);      //tc = 4^(n*m) total 4 option up down left and right each option pich or not pick
    //int up = count(i-1,j,n,m,arr);       //mark it do all the work and then unmark it
    //int left = count(i,j-1,n,m,arr);

    //simply write
    int cnt =0;
    for(int a =0;a<4;a++){
        if(isvalid(i+di[a],j+dj[a],n,m,arr)){
        path.push_back(dir[a]);
        generate(i+di[a],j+dj[a],n,m,arr,path);
        path.pop_back();}
    } 
    //i will unmark it 
    arr[i][j]=0;
}

signed main (){
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j =0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    string path="";
    generate(0,0,n,m,arr,path);
return 0;
}