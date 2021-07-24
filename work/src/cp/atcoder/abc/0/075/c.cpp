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
    int lastunited;
    unionfind(size_t sz): data(sz,-1) {}
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
        lastunited=-data[x];
        return true;
    }
    void reset(size_t n){
        data.assign(n,-1);
        lastunited=0;
    }
};

int main(){
    int n,m;cin>>n>>m;
    unionfind uni(n);
    vc<P> edges(m);
    rep(i,m){
        int a,b;cin>>a>>b;
        a--;
        b--;
        edges[i]={a,b};
    }

    int ans=0;
    rep(i,m){
        uni.reset(n);
        rep(j,m){
            //辺iを除いた辺によって頂点を繋いでいったときに連結グラフになるかどうか判定する.
            if(j==i)continue;
            uni.unite(edges[j].fi,edges[j].se);
        }
        if(uni.lastunited!=n)ans++;
    }
    cout<<ans<<endl;

    return 0;
}

/*
unionfindを使う解法を考える.辺の本数は高々50本なので,50本それぞれについて橋かどうかの判定を行っても良さそうである.
一つの辺を除いた辺全てについて,両端の頂点に対してマージ操作を行っていって,最終的に出来た集合の内の一つを取ったときに,それが全ての頂点を含んでいない時,その一つの辺は橋であるといえる.
計算量:マージ操作は高々lognなので各辺に対して,O(50*logn)程度これを50回行ってもTLEしないのでOK.
*/