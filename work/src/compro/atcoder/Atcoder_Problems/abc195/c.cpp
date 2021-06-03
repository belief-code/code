#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int,int>;

int main(){
    ll n;cin>>n;
    vector<ll> numset(6);
    rep(i,6){
        numset[i]=pow(10,3*(i+1))-pow(10,3*(i));
    }
    
    ll ans;
    ans=n*((to_string(n).size()-1)/3);
    rep(i,to_string(n).size()/3){
        ans-=numset[i]*((to_string(n).size()-1)/3-i);
    }
    cout<<ans<<endl;

    return 0;
}