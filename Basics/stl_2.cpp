#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n' 
#define INF = LLONG_MAX>>1
const int MOD = 1e9 +7;
 
bool compare(int a,int b){
    //if(/*a should be placed trictly before b*/){
        return abs(a)<abs(b);// if no comparator is defined it is taken as return a<b 
}
bool compare1(pair<int,int> a,pair<int,int>b){
    if(a.first!=b.first){
        return a.first<b.first;
    }
    return a.second<b.second;
}
bool cmp(int a,int b){
    return a>b;
}
vector<pair<vector<pair<string,vector<int>>>,int>>p;
signed main (){
    ios::sync_with_stdio(false);cin.tie(NULL);
    deque<int>d{9,1,7};
    d.push_back(5);
    d.push_back(2);
    d.push_back(3);
    sort(d.begin(),d.end());
    for(auto i:d){cout<<i<<" ";}
    cout<<endl;

    d.pop_back();
    d.pop_front();
    d.push_front(9);   //marginally slow than vector but ok wont give tle
    for(auto i:d){cout<<i<<" ";}
    cout<<endl;

    //sort(begin(),end(),comparator)             //TC = nLogn*TC(comparator)
    //sort 1 -1 2 3 -8 -3 -4 5 -2 based on magnitude here we make use of comparator 
    vector<int>v{1,1,2,3,-8,-3,-4,5,-2};
    sort(v.begin(),v.end(),compare);

    for(auto i:v){cout<<i<<" ";}
    cout<<endl;
    int a[]{1 ,2,3 ,5 ,7 ,8};
    cout<<binary_search(a,a+6,4)<<endl;
    cout<<binary_search(a,a+6,2)<<endl;

    //binary_search(boolean),lower_bound,upper_bound stl function 
    //lower_bound return iteratior to the firt occurance of value >= target
    //upper_bound return iteratior to the firt occurance of value > target
    //Lower_bound -1 < target
    //Upper_bound -1 <=target  //last value less than or equal to target

    //for something like sorted datatype where we cant access value like set
    set<int>s1{1,2,3,5,6,7};
    cout<<*s1.lower_bound(4)<<endl;  //here lb knows what i inside set.lower_bound 
    cout<<*(--s1.lower_bound(4))<<endl; //element just lower than 4
    auto it = s1.upper_bound(2);
    if(it!=s1.begin()){
        cout<<*(--it)<<endl;
    }
    //if lowerbound(s.begin(),s.end(),target) thenTc = O(n) since upperbound cant access set value 
    //it starts from s.begin() and compares it with target then move till num greater than target is found
 


    //Priority QUEUE
    priority_queue<int>pq;     // //max heap  will output largest value first
    pq.push(4);pq.push(2);pq.push(9);pq.push(5);pq.push(2);  
    //arranged based on priority i.e larger number will be on top
    while(!pq.empty()){
        cout<<pq.top();
        pq.pop();
    }
    cout<<endl;

    //        Default storage Datatype   Comparator
    priority_queue<int,vector<int>,greater<>>pq1;  //min heap output smallest value first
     //vector<int> has nothing to do with sorting it is just a representation of priority queue
    pq1.push(4);pq1.push(2);pq1.push(9);pq1.push(5);pq1.push(2); 
    while(!pq1.empty()){
        cout<<pq1.top();
        pq1.pop();
    }
    cout<<endl;

    //Use of comparator IN priority Queue and set
    priority_queue<int,vector<int>,decltype(&cmp)>pq2(&cmp);  
    //In set we cant do s.lower_bound(5,cmp) instead we can do
    // set<int,decltype(&cmp)>s1(cmp);  //comprator for set
     //map<int,int,decltype(&cmp)>mp(cmp);
}