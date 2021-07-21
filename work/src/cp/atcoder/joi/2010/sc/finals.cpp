#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define rep(i,n) for(int i=0;i<(n);++i)
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
    unionfind(size_t sz) :data(sz,-1) {}
    bool unite(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return false;
        if(data[x]<data[y])swap(x,y);
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
    int n,m,k;cin>>n>>m>>k;
    vc<tuple<int,int,int>> edges;
    unionfind mst(n);
    rep(i,m){
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        edges.eb(c,a,b);
    }
    sort(edges.begin(),edges.end());
    int count=0;
    ll ans=0;
    rep(i,m){
        if(mst.unite(get<1>(edges[i]),get<2>(edges[i]))&&count<=n-k-1){
            count++;
            ans+=get<0>(edges[i]);
        }
    }
    cout<< ans<<endl;
    return 0;
}

/*
注意:無向グラフ、N頂点M辺、重み付き
最小全域木にする必要はない。K個の最小全域木を作ればいいので、
N-K本小さい順に辺を追加すればそれで事足りる
*/