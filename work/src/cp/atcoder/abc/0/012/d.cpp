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
    int n,m;cin>>n>>m;
    vvi g(n,vi(n,INF));
    rep(i,m){
        int a,b,t;cin>>a>>b>>t;
        a--;b--;
        g[a][b]=t;
        g[b][a]=t;
    }
    vvi d(n,vi(n,INF));
    //テーブルの初期化
    rep(i,n){
        rep(j,n){
            if(i==j)d[i][j]=0;
            else d[i][j]=g[i][j];
        }
    }

    //経由可能頂点はiまで
    rep(i,n){
        //始点j
        rep(j,n){
            //終点k
            rep(k,n){
                //int型は2147483647まで保存できるので後者はオーバーフローしない
                //また負辺が存在しないので変な値が入ることもない
                d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
            }
        }
    }

    //各始点について最長時間を比較する。
    int ans=INF;
    rep(i,n){
        int maxtime=0;
        rep(j,n){
            maxtime=max(maxtime,d[i][j]);
        }
        ans=min(ans,maxtime);
    }
    cout<<ans<<endl;
    return 0;
}


/*考察
結局のところ各始点各終点についてテーブルを埋める必要がある、つまりテーブルを埋める問題である。
ここで、負辺がないので、
-各始点についてダイクストラ法を行い行ごとに埋めていく解法
-ワーシャルフロイド法でテーブル全体を一気に埋める解法
の2つがある。この2つの計算量を比較する。(場合によっては前者のほうが早いこともある(辺が疎な場合))
前者の最悪計算量は300*44850*log(300)
後者は300*300*300
よって後者のほうが早いので(ダイクストラ法もうちょっと早いパターンとかもあるかもしれない)
ワーシャルフロイド法で解く。
*/