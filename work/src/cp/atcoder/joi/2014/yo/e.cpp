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
    int n,k;cin>>n>>k;
    vi c(n),r(n);
    rep(i,n){
        cin>>c[i]>>r[i];
    }
    vvi g(n);
    rep(i,k){
        int a,b;cin>>a>>b;
        a--;
        b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    vvi realg(n);
    rep(i,n){
        queue<int> que;
        vi dist(n,-1);
        que.push(i);
        dist[i]=0;
        while(!que.empty()){
            int v=que.front();
            que.pop();
            //距離がr[i]の頂点網羅したらそれ以上は辺を追加しない
            if(dist[v]==r[i])break;
            for(int nv:g[v]){
                if(dist[nv]!=-1)continue;
                dist[nv]=dist[v]+1;
                que.push(nv);
                realg[i].pb(nv);
            }
        }
    }
    vi mincost(n,INF);
    //{cost,vertex}今回は制約上コストがintで足りるのでただのペアでやってる
    priority_queue<P,vp,greater<>> pq;
    pq.emplace(0,0);
    mincost[0]=0;
    //こっから下は典型的なダイクストラ法なので言うことはあんまりない
    while(!pq.empty()){
        int cost,v;
        tie(cost,v)=pq.top();
        pq.pop();
        if(cost>mincost[v])continue;
        for(int nv:realg[v]){
            int ncost=cost+c[v];
            if(ncost>=mincost[nv])continue;
            mincost[nv]=ncost;
            pq.emplace(ncost,nv);
        }
    }
    cout<<mincost[n-1]<<endl;
    return 0;
}

/*初回考察
非負辺グラフの最小コスト経路問題なので、小問題への読み替えを行う。
　出来るだけ早く適当な最小コスト経路が確定していない頂点の最小コスト経路を確定せよ。
と読み替えられる。
これはどのように実現可能か考える。フローチャートに則って初手から考えると、
初手で到達可能な頂点は初手からタクシーで移動することが全て最小コスト経路となる。
次に二手目を考えると、最小コスト経路が確定した頂点の中で最も料金の安い町から到達可能な頂点は、
任意の他の町からタクシーを使って到達する料金以下で到達出来るので、最小コスト経路として確定出来る。
このことを優先度付きキューを用いて繰り返すことでダイクストラ法的に頂点を最小コスト経路で原点と繋いで行くことが出来る。
これは正しそうである。また到達可能頂点はBFSによって計算されるので計算量に注意。
これ到達可能頂点事前計算したい。あまりにもめんどくさいまじで。
*/

/*AC後感想
バグ一つのバグ取り5秒位でACしてくれた。
一般性の高い考察が身についてきているような気もするし、その程度のレベルな気もしている。
でもこのレベルの問題を機械的に解けることは悪いことではなさそうなのでとりあえず良しとする。
*/