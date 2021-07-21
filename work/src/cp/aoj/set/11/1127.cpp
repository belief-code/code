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
        return true;
    }
};

struct positionr{
    double x,y,z,r;
    positionr () {}
    positionr(double a,double b,double c,double d): x(a),y(b),z(c),r(d) {}
};

double distcor(positionr a,positionr b){
    return max(0.0,sqrt(pow(a.x-b.x,2.0)+pow(a.y-b.y,2.0)+pow(a.z-b.z,2.0))-a.r-b.r);
}

int main(){
    while(1){
        int n;cin>>n;
        if(n==0)break;

        unionfind mst(n);
        vc<positionr> posit(n);
        rep(i,n){
            double x,y,z,r;cin>>x>>y>>z>>r;
            posit[i]=positionr(x,y,z,r);
        }
        double ans=0;
        vc<tuple<double,int,int>> edges;
        //完全グラフを成すような辺の構成
        rep(i,n){
            srep(j,i+1,n){
                edges.eb(distcor(posit[i],posit[j]),i,j);
            }
        }
        sort(edges.begin(),edges.end(),[](const tuple<double,int,int> &a,const tuple<double,int,int> &b){
            return get<0>(a)<get<0>(b);
        });
        rep(i,edges.size()){
            if(mst.unite(get<1>(edges[i]),get<2>(edges[i]))){
                ans+=get<0>(edges[i]);
            }
        }
        cout<<fixed<<setprecision(3)<<ans<<endl;
    }
    return 0;
}

/*
unionfindで頂点を予め繋がっているものに関してまとめておく。
完全グラフを形成するように辺を候補に一つ一つ入れていく。
ソートして最小のものからクラスカルを用いて最小全域木になるように選択していく。
元から接しているものについては長さ0の辺がついているとして扱えばよい。
*/

/*
沢山構造体を作ってみた。ラムダ式も使ってみた。
エラー500行くらい最初のコンパイルで吐いて直すのに15分くらいかかった。
そこで思ったこと書く
-コンストラクタはただのオブジェクト生成用のやつを一つ書いておくといい。
ここでいうvector<positionr> posit(n);でバグった。positionr() {}を構造体内に作らないと
未定義動作になる。
-ソート関数で渡すラムダ式は要素を引数とするようなものにしないといけない(あたりまえやカス)。
-ソート関数では第一項が比較された後、二項目が比較されるが、それをさせると未定義動作になる場合には、
無視させるようなラムダ式を渡して回避するといい。
-正直tuple使うより構造体作ったほうが色々都合がいい気がする。
*/