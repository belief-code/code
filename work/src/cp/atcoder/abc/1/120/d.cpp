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
    ll inconvenience;
    unionfind(size_t sz) :data(sz,-1) {
        inconvenience=(sz*(sz-1))/2;
    }
    int find(int k){
        if(data[k]<0)return k;
        return data[k]=find(data[k]);
    }

    bool unite(ll x,ll y){
        x=find(x);y=find(y);
        if(x==y)return false;
        inconvenience-=data[x]*data[y];
        if(data[x]>data[y])swap(x,y);
        data[x]+=data[y];
        data[y]=x;
        return true;
    }
};

int main(){
    int n,m;cin>>n>>m;
    vc<P> edges(m);
    rep(i,m){
        int a,b;cin>>a>>b;
        a--;b--;
        edges[i]={a,b};
    }
    //処理しやすいように辺を追加しておく
    edges.eb(0,0);


    //橋0については考える必要がないことに注意
    unionfind uni(n);
    vc<ll> ans(m);
    rep(i,m){
        uni.unite(edges[m-i].fi,edges[m-i].se);
        ans[m-1-i]=uni.inconvenience;
    }
    rep(i,m){
        cout<<ans[i]<<endl;
    }
    return 0;
}

/*
最終状態から考えると,辺を足していく感じになる,つまりマージ操作を一回ずつ行っていけばいい感じになる.答えを配列に記録していけば良い.
組の数については,集合を一つ一つ順番に見ていって,その集合に含まれない∧これまでに見ていない要素とのペアのみを足し合わせていけば重複なく求められるので,これをunionfindの配列上で行う.これ通ると思ってたけど普通にO(10^10)になってTLEした.ちゃんと確認すべきだった.
なので,マージ操作によってどれだけ不便さがなくなるのかの計算が簡単なので,そのことを用いて,各マージ操作において不便さからなくなる不便さを引いていって求めることにした.
*/