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

//構造体書かないと忘れるから作っておく.普通にtupleでいいけどね.
struct biome{
    int jungle=0;
    int ocean=0;
    int ice=0;

    biome() {}
    biome (int a,int b,int c): jungle(a),ocean(b),ice(c) {}
    biome operator+(const biome &other){
        biome ret;
        ret.jungle=jungle+other.jungle;
        ret.ocean=ocean+other.ocean;
        ret.ice=ice+other.ice;
        return ret;
    }
    biome operator-(const biome &other){
        biome ret;
        ret.jungle=jungle-other.jungle;
        ret.ocean=ocean-other.ocean;
        ret.ice=ice-other.ice;
        return ret;
    }
};


int main(){
    int m,n;cin>>m>>n;
    int k;cin>>k;
    //二次元累積和は各格子点に対して定義すると良さそう(1次元累積和と同じ考え)
    vv<biome> sum(m+1,vc<biome>(n+1));
    rep(i,m){
        string s;cin>>s;
        rep(j,n){
            biome tmp;
            if(s[j]=='J')tmp.jungle++;
            if(s[j]=='O')tmp.ocean++;
            if(s[j]=='I')tmp.ice++;
            sum[i+1][j+1]=sum[i][j+1]+sum[i+1][j]-sum[i][j]+tmp;
        }
    }
    rep(i,k){
        int a,b,c,d;cin>>a>>b>>c>>d;
        a--;b--;
        biome tmp=sum[c][d]-sum[c][b]-sum[a][d]+sum[a][b];
        cout<<tmp.jungle<<" "<<tmp.ocean<<" "<<tmp.ice<<endl;
    }
    return 0;
}

/*
二次元累積和を用いると各クエリに対してO(1)で解ける.
前処理にO(M*N)かかるが,これは時間内に可能.
二次元累積和初めて書くけど,結構たのしそう.
*/