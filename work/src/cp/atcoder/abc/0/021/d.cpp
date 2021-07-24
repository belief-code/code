#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define rep(i,n) for(int i=0;i<(n);++i)
#define srep(i,s,t) for (int i = s; i < (t); ++i)
using namespace std;
template<class T> using vc = vector<T>;
template<class T> using vv = vc<vc<T>>;
using ll = long long;
using P = pair<int,int>;
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const ll mod=1000000007;

ll inverse(ll x){
    ll ret=1,index=mod-2;
    while(index>0){
        if(index&1)(ret*=x)%=mod;
        (x*=x)%=mod;
        index>>=1;
    }
    return ret;
}


int main(){
    ll n,k;cin>>n>>k;
    ll ans=1;
    rep(i,k){
        (ans*=n+k-1-i)%=mod;
        (ans*=inverse(i+1))%=mod;
    }
    cout<<ans<<endl;
    return 0;
}

/*
重複ありの選択問題なので,仕切りの数とボールの数とかと対応させて(n+k-1)Ckが答えとなる.
フェルマーの小定理と二分累乗法を用いてこれを求める.
*/