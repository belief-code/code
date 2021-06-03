#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;cin>>n;
    string s;cin>>s;
    int ans=0;
    for(int i=0;i<n-2;i++){
        if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C') ans++;
    }
    cout<<ans<<endl;
    return 0;
}