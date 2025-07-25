
// https://cses.fi/problemset/result/9319258/

#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n' 
#define INF = LLONG_MAX>>1
const int MOD = 1e9 +7;
 
signed main (){
ios::sync_with_stdio(false);cin.tie(NULL);
{
    string s;
    cin>>s;
    vector<int>count(26,0);
    for(auto i:s){
        count[-'A'+i]++;
    }
    int f =1;
    string s2(s.size(),' ');
    if(s.size()%2==0){
        for(auto i :count){
            if(i%2==0){
                f&=f;
            }
            else{
                f=0;
                break;
            }
        }
        if(f==0){
            cout<<"NO SOLUTION"<<endl;
            return 0;
        }
        for(int i=0;i<26;i++){
            int x = count[i]/2;
            while(x--){
                s2+=(char)('A'+i);
            }
        }
        cout<<s2;
        reverse(s2.begin(),s2.end());
        cout<<s2<<endl;
    }
    else{
        char a;
        int f =0;
        int j=0;
        for(auto i :count){
            if(i%2!=0){
                f++;
                a = (char)('A'+j);
            }
            j++;
        }
        if(f!=1){
            cout<<"NO SOLUTION"<<endl;
            return 0;
        }
        else{
        for(int i=0;i<26;i++){
            int x = count[i]/2;
            while(x--){
                s2+=(char)('A'+i);
            }
        }
        cout<<s2;
        reverse(s2.begin(),s2.end());
        cout<<a;
        cout<<s2<<endl;
    }
    }
}
return 0;
}