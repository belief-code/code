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
vv<ll> a,suma;
ll h,w,k,v;
bool isOK(ll sh,ll sw,ll sw2,ll eh){
    ll value;
    value=suma[eh][sw2]-suma[eh][sw]-suma[sh][sw2]+suma[sh][sw]+k*(eh-sh)*(sw2-sw);
    return value<=v;
}

ll nibutan(ll sh,ll sw,ll sw2){
    ll ok=sh;
    ll ng=h+1;
    while(abs(ok-ng)>1){
        ll mid=(ok+ng)/2;
        if(isOK(sh,sw,sw2,mid))ok=mid;
        else ng=mid;
    }
    ll ret=(ok-sh)*(sw2-sw);
    return ret;
}

int main(){
    cin>>h>>w>>k>>v;
    a.assign(h,vc<ll>(w));
    suma.assign(h+1,vc<ll>(w+1,0));
    rep(i,h){
        rep(j,w){
            cin>>a[i][j];
            suma[i+1][j+1]=suma[i][j+1]+suma[i+1][j]-suma[i][j]+a[i][j];
        }
    }
    ll ans=0;
    rep(i,h){
        rep(j,w){
            srep(k,j+1,w+1){
                ans=max(ans,nibutan(i,j,k));
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

/*
土地の選び方がおよそ10^8,二次元累積和を持っておけば各選び方に対しての計算量はかなり下げられる.
これでもギリギリ行けそう.
2点で長方形を表す時,それぞれを始点終点と呼ぶことにする.
適当に始点を選んだ時,その始点に対応するベストな終点は二分探索を用いることで少し早く求められる.これを使うと,合計で計算量がO(H*W*H*log(W))になるので多分行ける.
*/