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
    int n;cin>>n;
    vvi g(n,vi(n));
    rep(i,n){
        rep(j,n){
            cin>>g[i][j];
        }
    }
    ll ans=0;
    rep(i,n){
        rep(j,n){
            bool flag=0;
            rep(k,n){
                if(g[j][k]>g[j][i]+g[i][k]){
                    cout<<-1<<endl;
                    return 0;
                }
                if(g[i][j]==g[i][k]+g[k][j]&&k!=i&&k!=j)flag=1;
            }
            if(!flag)ans+=g[i][j];
        }
    }
    cout<<ans/2<<endl;

    return 0;
}

/*考察
注意:重み付き無向連結グラフ
　テーブルからグラフを復元する問題。
　とりあえず結構アプローチがきついから可能なアプローチから考えていく、和が最小となるのは、
このグラフから想定できる橋の中から最短経路で使うものだけ残したらそれでいいような気もする。
　道の長さの総和を最小にするってのは、つまり最初にテーブルの要素を全部足して、共有するパスの長さを
引いていく。みたいな方法でできそう。あとは普通に道を構成する方法だけど、こっちはかなり大変。
　てか、一回完全グラフにして、取り除ける辺を大きい方から調べていけばそれでいいのかもしれない。
　条件を満たす道路の構造が存在しない場合は、ワーシャルフロイド法を用いて、完全グラフの最短経路を
マッピングしていった時にそれが与えられるテーブルと異なるか判定すれば良い？
　辺を取り除けるかは、終点の隣接頂点への最短経路を全部見ていって(V通り)そこからの最短経路を足した時に
元の最短距離になるものが一つでもあれば消しても良いと判定できる。
　上から貪欲に取っていっても良さそうなのはそうなんだけど正当性を示すのが難しい。
最終的に最短経路候補が余分に残っているっていう状況はまず良くない。二通りの最短経路がある場合には、
ノードを一つも経由しない場合よりも、複数個のノードを経由する場合のほうが、そのノード間の
経路を他の最短経路で共有できる可能性が高いので、一概に長い経路を切ったほうがいい。
こんな感じでとりあえず直で行ける最短経路以外にも最短経路がある場合にはちょくで行ける最短経路は切ったほうがいいことは示せる。
次に、直で行ける最短経路を切っていった時に最終形の辺の長さの総和がそれ以上短くならないのか考える。
もしもそれ以上短く出来るのであれば、その時に切ることの出来る辺は、なんらかの最短路になっていなくてはならないが、
切れる最短路はすでに全て切っているのでこれは矛盾する。
　よって最短路が他の経路で代用できるような辺は切ることが出来る。また切ることが出来るかの判定は、
どのような順番で切っていっても可能である。つまりすでに切られている状態で切れるかどうかの判定をする必要はなく、
全てが繋がっている状態で、それが他の経路で代替可能かどうかだけ確かめればよい。というのも、もしもその代替経路内のどこかの
辺が切られていたとしても、切ることが可能な辺であればそれはまた違う経路によって代替可能であるからである。
　結局、全ての辺について、それが代替可能かどうかを判定していき、代替可能でないものの長さだけ答えに足していけば、
最終的にそれが答えになる。ここで考えているのは無向グラフなので、余分に足される分引いておく。
　結局の所、可能なグラフかどうかの判定でも、代替不可能な辺を判定して加算していくときも、グラフの書き換えは必要ない上に、
同じ3重ループで判定可能なので、同時にどっちも3重ループ内で出来る。なのでそのように実装した。
*/