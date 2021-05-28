#include<iostream>
#include<string>
using namespace std;

int main(){
    string s,p;
    cin>>s>>p;
    s+=s;
    if(s.find(p)==string::npos) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}