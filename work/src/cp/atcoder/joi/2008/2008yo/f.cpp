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

struct Graph{
    int n;
    //運賃の合計がintだとオーバーフローしそうだから運賃らへんはlonglongにしておく
    vv<pair<int,ll>> g;
    explicit Graph(int k) : g(k),n(k) {}
    void addedge(int c,int d,ll e){
        c--;
        d--;
        g[c].eb(d,e);
        g[d].eb(c,e);
    }
    ll dijkstra(int a,int b){
        using Pi=pair<ll,int>;
        a--;
        b--;
        vl dist(n,LINF);
        priority_queue<Pi,vc<Pi>,greater<>> que;
        que.emplace(0,a);
        dist[a]=0;
        while(!que.empty()){
            ll cost;int v;
            tie(cost,v)=que.top();
            que.pop();
            if(cost!=dist[v])continue;
            for(auto nv:g[v]){
                ll newcost=cost+nv.se;
                if(newcost>=dist[nv.fi])continue;
                dist[nv.fi]=newcost;
                que.emplace(newcost,nv.fi);
            }
        }
        if(dist[b]==LINF)return -1;
        return dist[b];
    }
};


int main(){
    int n,k;cin>>n>>k;
    Graph G(n);
    rep(i,k){
        bool flag;
        cin>>flag;
        if(flag){
            int c,d;ll e;cin>>c>>d>>e;
            G.addedge(c,d,e);
        }else{
            int a,b;cin>>a>>b;
            cout<<G.dijkstra(a,b)<<endl;;
        }
    }
    return 0;
}

/*
　両端ダイクストラやると多分平均計算量下がるけど、最悪計算量ほぼ変わらない気がするから
普通のダイクストラやる。
　グラフの構造体作ってその中にメンバ関数としてダイクストラ入れたらキレイにできそう。
　計算量については、注文クエリのときだけダイクストラを動かすとすると、一回のクエリに対して
最悪1000log100~7000これが高々5000回で35000000で間に合う。
なんなら運行情報のたびにダイクストラ回しても間に合う。
*/