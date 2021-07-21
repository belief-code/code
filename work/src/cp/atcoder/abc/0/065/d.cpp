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

struct unionfind{
    vc<int> data;
    unionfind () {}
    unionfind(size_t sz) : data(sz,-1) {}
    int find(int k){
        if(data[k]<0)return k;
        return data[k]=find(data[k]);
    }
    bool unite(int x,int y){
        x=find(x);y=find(y);
        if(x==y)return false;
        if(data[x]>data[y])swap(x,y);
        data[x]+=data[y];
        data[y]=x;
        return true;
    }
};

struct edge{
    int from;
    int to;
    int weight;
    edge() {}
    edge(int a,int b,int c) : from(a),to(b),weight(c) {}
};

int main(){
    int n;cin>>n;
    vc<P> x(n);
    vc<P> y(n);
    rep(i,n){
        int tempx,tempy;cin>>tempx>>tempy;
        x[i]={tempx,i};
        y[i]={tempy,i};
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    vc<edge> edges;
    rep(i,n-1){
        edges.emplace_back(x[i].se,x[i+1].se,x[i+1].fi-x[i].fi);
        edges.emplace_back(y[i].se,y[i+1].se,y[i+1].fi-y[i].fi);
    }
    sort(edges.begin(),edges.end(),[](const edge &a,const edge &b){
        return a.weight<b.weight;
    });
    unionfind mst(n);
    ll ans=0;
    rep(i,edges.size()){
        if(mst.unite(edges[i].from,edges[i].to)){
            ans+=edges[i].weight;
        }
    }
    cout<<ans<<endl;
    return 0;
}

/*貪欲法の正当性の証明
最小のものから全域木を構成できることが確定している候補についてのみクラスカル法を行えば
十分。全頂点からの最短辺を二辺列挙すると、これで全域木を構成できることは保証できる(自明)
また、これは結局全ての辺の中から最短のものを含む2n-2本の辺になっているので要請を満たす。
*/