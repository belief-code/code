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
    unionfind(size_t sz) :data(sz,-1){}
    int find(int k){
        if(data[k]<0)return (k);
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
    void same(int x,int y){
        x=find(x);y=find(y);
        if(x==y)cout<<1<<endl;
        else cout<<0<<endl;
    }
};

int main(){
    int n,q;cin>>n>>q;
    unionfind uni(n);
    rep(i,q){
        int com,x,y;cin>>com>>x>>y;
        if(com==0)uni.unite(x,y);
        else uni.same(x,y);
    }
    return 0;
}

/*
unionfindそのまま.
*/