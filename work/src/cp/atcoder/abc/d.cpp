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
    int n,q;cin>>n>>q;
    vvi G(n);
    rep(i,n-1){
        int a,b;cin>>a>>b;
        a--;
        b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    vi dist(n,-1);
    queue<int> que;
    dist[0]=0;
    que.push(0);
    while(!que.empty()){
        int v=que.front();
        que.pop();
        for(int nv:G[v]){
            if(dist[nv]!=-1)continue;
            dist[nv]=dist[v]+1;
            que.push(nv);
        }
    }

    rep(i,q){
        int c,d;
        cin>>c>>d;
        c--;
        d--;
        if(abs(dist[c]-dist[d])%2==0)cout<<"Town"<<endl;
        else cout<<"Road"<<endl;
    }
    return 0;
}
//街は木になってる
//最短路が奇数長だとぶつかる
//