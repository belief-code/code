#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;cin>>s;
    string ans="";
    ans.push_back(s[1]);
    ans.push_back(s[2]);
    ans.push_back(s[0]);
    cout<<ans<<endl;

    return 0;
}

//答えを入れる変数が必要か考えたほうが良い