#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n' 
#define INF = LLONG_MAX>>1
const int MOD = 1e9 +7;
 
signed main (){
    ios::sync_with_stdio(false);cin.tie(NULL);
    pair<int,string>p={1,"sri"};
    cout<<p.first<<endl;
    cout<<p.second<<endl;

    vector<int>v{1,2,4,5,6};
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    
    v.insert(v.begin()+2,3);   //O(n) not O(1)

    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    v.erase(v.begin()+1);     //v.clear removes every element
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<endl;

    //SET
    set<int>s={1,5,4,3,2,2,4};
    for(auto i:s){
        cout<<i<<" ";
    }
    cout<<endl;
    s.insert(7);s.erase(4);
    if(s.find(7)!=s.end()){        //iske badle contains ==> o(logn) since set is sorted is performs binary search 
        cout<<"Yes"<<endl;    //s.find()!=s.end()
    }
     for(auto i:s){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<endl;

    //MAP
    map<int,int>mp;
    mp[1]=5;
    mp[1]=7;
    mp[1e5]=9;
    mp.erase(1);
    mp.insert({1,5});
    mp.insert(make_pair(5,9));//in pair we have tell if the value or key is string int etc in make_pair there is no need
    for(auto [a,b]:mp){          //shows what is stored  in mp  cant use auto i:mp
        cout<<a<<" "<<b<<endl;
    }
    auto it = mp.find(5);  //only accesses key 
    cout<<(*it).second<<endl;
    cout<<endl; 

    //Unordered set
    //unordered_set<pair<int,int>>p; cannot work as pair does not have hash function.
    set<pair<int,int>>s2;    //no error as pairs are comparable
    unordered_set<int>s1 = {1,2,4,1,4,555,42,34,4,2};
    for(auto i:s1){
        cout<<i<<" ";
    }
    cout<<endl;

    //Multiset EXample 

    
    int t;
    cin>>t;
    while(t--){
        int n,p;
        cin>>n>>p;
        multiset<int>mult;
        int cnt =0;
        for(int i =0;i<n;i++){
            int a;
            cin>>a;
            mult.insert(a);
        }
        while(p>0&&mult.size()){
            cnt++;
            int mx = *mult.rbegin();
            mult.erase(--mult.end());
            p -=mx;
            mx/=2;
            if(mx>0)
            mult.insert(mx);
        }
        if(p<=0){
            cout<<cnt<<endl;
        }
        else{
            cout<<"Evacuate"<<endl;
        }
    }

    return 0;
}