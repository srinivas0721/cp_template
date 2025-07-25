 #include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define INF = LLONG_MAX>>1
const int MOD = 1e9 +7;

//https://leetcode.com/problems/letter-combinations-of-a-phone-number/
//https://leetcode.com/problems/combination-sum-ii/submissions/1350666594/
//https://leetcode.com/problems/combination-sum/
//https://www.geeksforgeeks.org/problems/subset-sums2234/1
// https://leetcode.com/problems/subsets-ii/
//https://leetcode.com/problems/generate-parentheses/submissions/1336120315/
//https://leetcode.com/problems/palindrome-partitioning/
//https://leetcode.com/problems/climbing-stairs/ tells when to use dp

//Print number from 1 to n
void print(int i,int n){
    if(i==n){
        cout<<n<<" ";
        return;
    }
    cout<<i<<" ";
    print(i+1,n);
}
//Print Number from n to 1
void print1m1(int i){
    if(i==0){
        return;
    }
    cout<<i<<" ";
    print1m1(i-1);
}
//method 2
void print1m2(int i ,int n){
    if(i==n){                         //IMPORTANT
        cout<<i<<" ";
        return;
    }
    print1m2(i+1,n);
    cout<<i<<" ";
}
//Factorial
int fact(int n){
    if(n==0){
        return 1;
    }
    return fact(n-1)*n;
}
//Palindrome
bool pali(string s,int i){
    if(i>=s.size()-i-1){
        return true;
    }
    char a = s[i];
    char b = s[s.size()-i-1];
    if(a==b){
        return pali(s,i+1);
    }
    return false;
}
//Linear search
int linear(int x,vector<int>v,int i=0){
    if(i == v.size()){
        return false;
    }
    if(v[i]==x){
        return true;
    }
    return linear(x,v,i+1);
}
//Fibonacci Number 
int dp[100+1];
int fibo(int n){
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1){         //MEMORISATION USING DP
        return dp[n];
    }
    return dp[n]= fibo(n-1)+fibo(n-2);
}
signed main (){
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>v{1,3,5,4,5,9};
    print(1,n);
    cout<<endl;
    print1m1(n);
    cout<<endl;
    print1m2(1,n);
    cout<<endl;
    cout<<fact(n)<<endl;
    string s;
    cin>>s;
    cout<<pali(s,1)<<endl;
    cout<<linear(2,v)<<endl;
    memset(dp,-1,sizeof(dp));
    cout<<fibo(n)<<endl;
    return 0;

}