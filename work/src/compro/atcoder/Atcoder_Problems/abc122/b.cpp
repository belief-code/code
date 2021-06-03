#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int,int>;

int main(){
    string s;cin>>s;
    int ans=0;
    rep(i,s.size()){
        int count=0;
        for(int j=i;j<s.size();j++){
            if(s[j]=='A'||s[j]=='C'||s[j]=='G'||s[j]=='T')count++;
            else break;
        }
        if(ans<count)ans=count;
    }
    cout<<ans<<endl;
    return 0;
}