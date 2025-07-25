#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n' 
#define INF = LLONG_MAX>>1
const int MOD = 1e9 +7;

//Check if target is present in the array
bool search(vector<int>v,int  target){
    int left =0; 
    int right = v.size()-1;
    while(left<=right){
        int mid = (left+right)/2;            //if left = 2e9 right = 2e9 then (r+l)/2 will over flow sso we can do 
        if(v[mid]==target){                 //mid = (2*l+(r-l))/2; i.e mid = l + ((r-l)/2); hence no overflow
            return true;
        }
        if(v[mid]<target){                  //for binary search on infinite loop use r = LLong_MAX or omething like that
            left = mid+1;
        }
        if(v[mid]>target){
            right = mid-1;              
        }
    }
    return false;
}
//Find last index of target 
int findlast(vector<int>v ,int target){
    int left =0,right = v.size()-1;
    while(left<right){
        int mid = (left +right +1)/2;        //ceiled  
                                            //Find 1t Index of target mid = (l+r)/2 simple floor
        if(v[mid]<=target){                  // v[mid]>=target  right = mid;
            left = mid;                       //v[mid]<target   left = mid +1;
        }//(for any <= or >= if there is " = " then left or right = mid only always)
        if(v[mid]>target){                   //For checking if mid should be floored or ceiled we ee for what valueof mid 
            right = mid -1;                //in last index case if l=2 r =3 if mid=2(floored) there will be infinite loop
        }                           //so we ceiled in this case if we ceiled mid = right &infinite loop  
    }
    return (v[left]==target)?left:-1;
}// floor(left) or ceil(right):depends on which side is "changing"
//should lean towards "changing side"
//changing side will not have " = " to sign in if statement 
//in upper case right = mid -1 is changing while left remains mid only right so ceil 

signed main (){
ios::sync_with_stdio(false);cin.tie(NULL);
vector<int>v={1,1,1,2,2,3,3,3,5};
//predicate(i)={T,T,T,T(L),F(R),F,F,F,F}
cout<<search(v,9)<<endl;
cout<<findlast(v,2)<<endl;

//BY Predicate function      Easy Implementation
int n = v.size();
int target =3;               //No need for ceil or floor or mid +1 or mid -1
int l =-1,r=n;
while(r-l>1){
    int m = (l+r)/2;
    (v[m]<target)?l=m:r=m;   //for searching first element and for last element target v[m]<=target
}
cout<<r<<endl;
//at the end L = last true & R = first  False
//always remember the answer needed is always on the transition from T to F either it is T or F(i.e last true or first false)
//Find the predicate function such that answer is last true or first false just like for searching firt element 
//pred.funct. is v[m]<target and for last element pred.funct. is v[m]<=target
//cout l if last true or cout rif first false 

//FOR UPPER BOUND and LOWER BOUND refer NOTES

return 0;
}