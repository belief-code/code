#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for(int i=s;i<(t);++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define bn(x) ((1<<(x))-1)
using namespace std;
template<class T> using vc = vector<T>;
template<class T> using vv = vc<vc<T>>;
using ll = long long;
using uint = unsigned;
using ull = unsigned long long;
using P = pair<int,int>;
using T3 = tuple<int,int,int>;
using vi = vc<int>;
using vvi = vv<int>;
using vl = vc<ll>;
using vp = vc<P>;
using vt = vc<T3>;
int getInt(){int x;scanf("%d",&x);return x;}
template<typename T>T dup(T x, T y){return (x+y-1)/y;}
template<typename T>void uni(T& a){sort(rng(a));a.erase(unique(rng(a)),a.end());}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;


int main(){
    int V,E,r;cin>>V>>E>>r;
    vv<P> G(V);
    rep(i,E){
        int s,t,d;cin>>s>>t>>d;
        G[s].pb({t,d});
    }
    set<pair<ll,ll>> ms;
    vl ans(V,LINF);
    ans[r]=0;
    for(P v:G[r]){
        ms.insert({v.se,v.fi});
    }
    while(!ms.empty()){
        pair<ll,ll> v=*begin(ms);
        ms.erase(v);
        if(ans[v.se]!=LINF)continue;
        ans[v.se]=v.fi;
        for(P nv:G[v.se]){
            if(ans[nv.fi]!=LINF)continue;
            ms.insert({nv.se+v.fi,nv.fi});
        }
    }
    rep(i,V){
        if(ans[i]==LINF)cout<<"INF"<<endl;
        else cout<<ans[i]<<endl;
    }

    return 0;
}

//グラフ問題は解法フローチャートないから頑張ろう
//とりあえず最短経路は一応longlongで持ったほうがいい
//多分いい感じにやるとV+Eくらいにはなりそう。
//一応方針は立ったので、手順を紹介する。
//最初の点からの移動先の中で最も短いものはそれ以上短くなりえないので確定させる。
//最初の点からの移動先の中から確定した点を除き、確定した点からの移動先を付け足す。
//この中で最も短いものはそれ以上短くなりえないので確定させる。
//これは行うたびに最低一つ消すことが出来る。
//また、全ての辺について一回だけ考慮すればいい。
//これはmultisetを使うと辺情報の挿入がlogNで削除もlogN、最小値の取得1で、
//計NlogNかかるが、多分これは行ける(Eが500000以下なので)
//なんかバグらず普通にACした。setにpair入れるこの実装あんまりキレイじゃない気がする。
//普通はsetじゃなくてpriority_queue使って実装するらしいけど、ほぼ綺麗さ変わらない。
//牛さんのライブラリから学習する。