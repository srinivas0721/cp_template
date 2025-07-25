//https://codeforces.com/problemset/problem/1428/C
//                  GREEDY

/*
ek stack bana liya wo sab letter ke jo first "B" se pahile aate hai fir check kiya ki agar stack non zero agar hai to 
stack se ek element niklega(stck--) kyuki "?B" wale sab element niklenge fir agar next element B nhi hai to stack++ hoga

eg; [AA]BABAA --->[A]ABAA ----> [AA]BAA ---> [A]AA ---> [AAA]
    (stack)       (stk-1)       (stack+1)     (stack-1)   Stack+2
       2             1             2              1         3
*/

#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n' 
#define INF = LLONG_MAX>>1
const int MOD = 1e9 +7;

int main (){
ios::sync_with_stdio(false);cin.tie(NULL);
int t;
cin>>t;
while(t--)
{
    string s;
    cin>>s;
    int stack =0;
    for(int i =0;i<s.size();i++){
        if(stack&&s[i]=='B'){
        stack--;
        }
        else
        {
            stack++;
        }
    }
    cout<<stack<<endl;
}
return 0;
}
