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

ll modpow(ll a,ll b){
    ll ret=1;
    while(b>0){
        if(b&1) (ret*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return ret;
}
ll ADD(ll a,ll b){
    ll ret=(a+b)%mod;
    return ret;
}

int main(){
    int n,q;cin>>n>>q;
    vc<ll> a(n);
    rep(i,n){
        cin>>a[i];
    }
    vc<ll> dist(n-1);
    vc<ll> distsum(n);
    distsum[0]=0;
    rep(i,n-1){
        dist[i]=modpow(a[i],a[i+1]);
        distsum[i+1]=distsum[i]+dist[i];
    }
    ll ans=0;
    int from=0;
    rep(i,q){
        int to;cin>>to;
        to--;
        ans=ADD(ans,abs(distsum[to]-distsum[from]));
        from=to;
    }
    ans=ADD(ans,abs(distsum[0]-distsum[from]));
    cout<<ans%mod<<endl;
    return 0;
}

/*
距離の前計算を行っておき街1から,距離の累積和を持っておけば各移動の計算がO(1)で出来るので時間内に計算可能.
modを適当に使いすぎて間違えた.通したら考える.
*/

/*AC後感想
atcoder初めて一番バグ取りに時間かかった問題になった.
もともとのコードは累積和の配列を作るときの計算をdistsum[i+1]=ADD(distsum[i],dist[i]);としていた.
ここまではまあ別にこれでもなんとでも出来るけど,ここで注意すべきは,このようにすると,
累積和のくせに,後のほうが小さい.みたいな場合があることだ.
実際に,このままans=ADD(ans,abs(distsum[to]-distsum[from]));とすると,
absで符号を反転させたいのはfrom>toの場合のみなのにも関わらず(それ以外で反転させると意味のわからないことになる)それ以外でも反転することになってしまう.
これの解決方法としては,from>toの時とfrom<toのときで分けて計算してmodを取って出力の際に負の場合にはmodを足す.もしくはそもそも累積和を取る時にqの制約上累積和がそんなにでかくならない(距離をmod処理しておけば)ことを見越して,mod処理せずに取る.の2つの方法があるが,今回は実装が楽な後者を選んだ.
このように,absを使う際には,どの場合の符号を反転させたいのか,その場合以外に反転しないか,を確実に確認すべき.
*/