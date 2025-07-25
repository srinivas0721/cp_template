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
    int arr[7]={1,3,4,7,9,10,12};
    int prefi_sum[7]={0};
    prefi_sum[0]=arr[0];                        //TC = O(t*n) t is test cases
    for(int i=1;i<7;i++){
        prefi_sum[i]=prefi_sum[i-1]+arr[i];
    } 
    for(auto i:prefi_sum){
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
    int n,m;
    cin>>n>>m;
      // 2-D prefix sum
      int arr[n+1][m+1];
      int pre_sum[n+1][m+1];

      for(int i =1;i<=n;i++){
          for(int j=1;j<=m;j++){
              cin>>arr[i][j];
              pre_sum[i][j]= arr[i][j]+pre_sum[i-1][j]+pre_sum[i][j-1] - pre_sum[i-1][j-1];
          }
    }

    //Given q queries and [l,r] range we have add k in this range for all the q queries
    //Difference array arr[r]-=k;
    
    int n,q;
    cin>>n>>q;
    int arr[n+2]{};
    while(q--){
        int l,r,k;
        cin>>l>>r>>k;
        arr[l]+=k;    //add k from l to n        
        arr[r]-=k;    //subtracts k from r+1 to n
    }
    //prefix sum on difference array
    for(int i =1;i<=n;i++){
        arr[i] += arr[i-1];
    }
    for(int i =1;i<=n;i++)
    cout<<arr[i]<<" ";

    cout<<endl;

    //suffix sum
    /* refer notes page suff

}
return 0;
}