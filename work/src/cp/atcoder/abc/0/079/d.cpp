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
    int h,w;cin>>h>>w;
    vvi c(10,vi(10));
    rep(i,10){
        rep(j,10){
            cin>>c[i][j];
        }
    }

    //ワーシャルフロイド法のテーブルを用意し、初期化する
    vvi table(10,vi(10,INF));
    rep(i,10){
        rep(j,10){
            if(i==j)table[i][j]=0;
            else table[i][j]=c[i][j];
        }
    }

    //i:=経由可能数値
    rep(i,10){
        rep(j,10){
            rep(k,10){
                //始点j,終点k
                table[j][k]=min(table[j][k],table[j][i]+table[i][k]);
            }
        }
    }

    //以下は各計算量O(1)の非本質パート
    ll ans=0;
    rep(i,h){
        rep(j,w){
            int a;cin>>a;
            if(a==-1)continue;
            ans+=table[a][1];
        }
    }
    cout<<ans<<endl;
    return 0;
}

/*考察
　1~10の数字について必要最小コストを予め求めておくと各クエリに対してO(1)なので大丈夫そう。
適当な数値aを変換する最小コストはaから適当になんらかの数値達を経由して1にする、もしくは
aから直で1に変換する場合が考えられる。これは最小コスト経路問題なので最短経路問題の典型アルゴリズムの適用を
考える。
　これは詳細には、単一終点全点対間最短経路問題なので、え？って思うけど辺を全部逆向きにすると、
単一始点全点間最短経路問題にできてダイクストラ法が使える。
逆向きにしなくてもワーシャルフロイド法を使うとまあまあ早く解ける。
ダイクストラ法で解く場合とワーシャルフロイド法で解く場合を比較する。
-ダイクストラ法で解く場合は、これは完全グラフなので、二分ヒープを用いず解くとO(V^2)
-ワーシャルフロイド法の場合は、V^3
普通にどっちで解いてもTLEしない(V^3~1000)ので簡単に実装できるワーシャルフロイド法で解く
*/

/*AC後感想
実装が簡単なアルゴリズムはバグりにくくて体にいい
*/