#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n' 
#define INF = LLONG_MAX>>1
const int MOD = 1e9 +7;
 
signed main (){
ios::sync_with_stdio(false);cin.tie(NULL);
{
    /*vector<int> freq(14,0);
    for(int i=0;i<5;i++){
        int n;
        cin>>n;
        freq[n]++;
    }
    for(int i=1;i<=13;i++){
        for(int j=1;j<=13;j++){
            if(freq[i]==3&&freq[j]==2){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;*/

    //Prefix Sum  we also have suffix sum

    int arr[7]={1,3,4,7,9,10,12};
    int prefi_sum[7]={0};
    prefi_sum[0]=arr[0];                        //TC = O(t*n) t is test cases
    for(int i=1;i<7;i++){
        prefi_sum[i]=prefi_sum[i-1]+arr[i];
    } 
    for(auto i:prefix_sum){
        cout<<i<<" ";
    }
    //if the quetsion is find sum of elements from [L,R] if size of array <=1e6 max value of L or R is 1e6 so O(n) is very
    //large if we include testcases also so we need O(1) time complexity

    //Prefix Sum from [L,R] Trick is 
    //(Prefix_Sum[0,R]-Prefix_sum[0,L-1])
    
    int t;
    cin>>t;
    int prefix_sum[7]={0};
    prefix_sum[0]=arr[0];                        //TC = O(N) (Precomputation)
    for(int i=1;i<7;i++){
        prefix_sum[i]=prefix_sum[i-1]+arr[i];
    }
    while(t--){
        //code
        int l,r;
        cin>>l>>r;
        if(l!=1)                                
        cout<<prefix_sum[r]-prefix_sum[l-1]<<endl;   //TC = O(t*1)
        else
        cout<<prefix_sum[r]<<endl;            //Total TC = O(t+n) < O(t*N)(previous one)
    }
    //FInd which character appears maximum number of times
    map<char,int>mp;
    int maxi =0;
    string s;
    cin>>s;
    for(auto c:s){
        maxi = max(maxi,++mp[c]);
    }
    for(auto c:s){
        if(mp[c]==maxi){
            cout<<c<<endl;
        }
    }
}
return 0;
}
