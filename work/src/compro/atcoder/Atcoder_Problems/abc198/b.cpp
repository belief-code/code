#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string s;cin>>s;
    int count=0;
    int size=s.size();
    string revs;
    reverse(s.begin(),s.end());
    for(int i=0;i<size;i++){
        if(s[i]=='0') s+='0';
        else break;
    }
    
    revs=s;
    reverse(s.begin(),s.end());
    if(s==revs)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}