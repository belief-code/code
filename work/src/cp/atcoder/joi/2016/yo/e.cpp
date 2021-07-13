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
    int n,m,k,s;cin>>n>>m>>k>>s;
    ll p,q;cin>>p>>q;
    //町の情報と道の情報は分けて持つことにする
    //支配済みの町からの距離を持たせることにする。
    vi dist(n,-1);
    //まとめてBFSして危険な町のマッピングをするためにキューを用意しておく
    queue<int> que;
    rep(i,k){
        int c;cin>>c;
        c--;
        dist[c]=0;
        que.push(c);
    }
    vvi g(n);
    rep(i,m){
        int a,b;cin>>a>>b;
        a--;
        b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    //危険な街のマッピング(BFS)
    while(!que.empty()){
        int v=que.front();
        que.pop();
        for(int nv:g[v]){
            if(dist[nv]!=-1)continue;
            dist[nv]=dist[v]+1;
            que.push(nv);
        }
    }
    //Piにたどり着いて一泊するまでの必要経費と町の番号を入れる
    using Pi=pair<ll,int>;
    priority_queue<Pi,vc<Pi>,greater<>> pq;
    pq.emplace(0,0);
    vl mincost(n,LINF);
    mincost[0]=0;
    //ダイクストラ法もどきで確定できる町を取り込んでいく。最後の町は経費0に注意
    while(!pq.empty()){
        ll cost;int v;
        tie(cost,v)=pq.top();
        pq.pop();
        if(cost!=mincost[v])continue;
        for(int nv:g[v]){
            ll ncost;
            if(dist[nv]==0)continue;
            if(dist[nv]>s||dist[nv]==-1) ncost=cost+p;
            else ncost=cost+q;
            if(ncost>=mincost[nv])continue;
            mincost[nv]=ncost;
            pq.emplace(ncost,nv);
        }
    }
    //最後は宿泊しないので引いておく
    if(dist[n-1]>s||dist[n-1]==-1)cout<<mincost[n-1]-p<<endl;
    else cout<<mincost[n-1]-q<<endl;

    return 0;
}

/*
注意:街1,Nはゾンビに支配されていない。町1,Nでは宿泊の必要がない
　毎回一つの町については最小値を確定できるので、ダイクストラ法的な感じでやると解ける。
普通に有向グラフとしてみてダイクストラ法を当てはめてもいいけど柔らかい実装をしてみる
　複数クエリの問題じゃないから構造体作らずに解く
　危険な町のマッピングの計算量を考えていなかったので考える。
普通にBFSで支配済みの町からたどることをすると、一回の試行に高々V+E回でこれをV回行うのでTLEする。
全ての支配済みの町をキューに入れた状態からBFSを始めるとこれは回避出来る。いいね！
*/