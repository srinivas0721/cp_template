#include<iostream>
using namespace std;
int main(){
    char c;
    cin>>c;
    if(c>='A'&&c<='Z'){
        cout<<(char)(c+32);
    }
    else
    {
        cout<<(char)(c-32);
    }
    return 0;
}