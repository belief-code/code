#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;cin>>n;
    int ans=-1;
    rep(i,n+1){
        if(to_string(i).size()%2==1)ans++;
    }
    cout<<ans<<endl;
    return 0;
}