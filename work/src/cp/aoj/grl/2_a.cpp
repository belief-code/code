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

struct unionfind{
    vi data;
    unionfind(size_t sz) : data(sz,-1) {}

    bool unite(int x,int y){
        x=find(x),y=find(y);
        if(x==y)return false;
        if(data[x]>data[y])swap(x,y);
        data[x]+=data[y];
        data[y]=x;
        return true;
    }
    int find(int k){
        if(data[k]<0)return (k);
        return data[k]=find(data[k]);
    }
};

int main(){
    int v,e;cin>>v>>e;
    unionfind mst(v);
    vc<tuple<int,int,int>> edges;
    rep(i,e){
        int s,t,w;cin>>s>>t>>w;
        edges.eb(w,s,t);
    }
    sort(edges.begin(),edges.end());
    ll ans=0;
    rep(i,e){
        if(mst.unite(get<1>(edges[i]),get<2>(edges[i]))){
            ans+=get<0>(edges[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}

/*
Kruskalやるだけ。キレイにフルスクラッチしてみる。
*/