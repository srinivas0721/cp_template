#include <iostream>
#include<string>
using namespace std;
int main(){
    string bro1;
    string bro2;
    getline(cin,bro1);
    getline(cin,bro2);
    int  s1 = bro1.length()-bro1.find(" ");
    int count =0;
    int s2= bro2.length()-bro2.find(" ");
    for(int i =1;i<=s1;i++){
        if(bro1[bro1.length()-i]==bro2[bro2.length()-i]){
            continue;
        }
        else{
            count ++;
            break;
        }
    }
    if(count!=0){
        cout<<"NOT"<<endl;
    }
    else
    {
        cout<<"ARE Brothers"<<endl;
    }
    return 0;

}