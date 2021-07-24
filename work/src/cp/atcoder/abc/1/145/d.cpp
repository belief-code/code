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
    ll x,y;cin>>x>>y;
    ll tempx=2*y-x,tempy=2*x-y;
    if(tempx%3!=0||tempx<0||tempy%3!=0||tempy<0){
        cout<<0<<endl;
        return 0;
    }
    tempx/=3;tempy/=3;
    //(tempx+tempy)Ctempxを求める.
    ll ans=1;
    rep(i,tempx){
        (ans*=tempx+tempy-i)%=mod;
        (ans*=inverse(i+1))%=mod;
    }
    cout<<ans<<endl;
    return 0;
}

/*
列ベクトル(1,2),(2,1)のそれぞれを非負整数倍したものの結合で表せるかどうか判定して,その非負整数の組を用いると,よくあるコンビネーションの問題になる.
x=(2b-a)/3,y=(2a-b)/3;
*/