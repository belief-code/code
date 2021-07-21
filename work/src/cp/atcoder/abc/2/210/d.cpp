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
    ll h,w,c;cin>>h>>w>>c;
    vv<ll> a(h,vl(w));
    rep(i,h){
        rep(j,w){
            cin>>a[i][j];
        }
    }
    vv<ll> upadd=a;
    vv<ll> lowadd=a;
    vv<ll> minupadd(h,vl(w,LINF));
    vv<ll> minlowadd(h,vl(w,LINF));
    rep(i,h){
        rep(j,w){
            upadd[i][j]+=c*i;
            lowadd[h-1-i][j]+=c*i;
            rightadd
        }
    }
    rep(i,h){
        rep(j,w){
            if(i==0){
                minupadd[h-1-i][j]=uppadd[h-1-i][j]+a[h-1-i][j];
                minlowadd[i][j]=lowadd[i][j]+a[i][j];
            }else{
                minupadd[h-1-i][j]=min(minupadd[h-1-(i-1)][j],upadd[h-1-i][j]+a[h-1-i][j]);
                minlowadd[i][j]=min(minlowadd[i][j],lowadd[i][j]+a[i][j]);
            }
        }
    }
    //行ごとに各列の最善に対応する最善要素を計算していく
    ll ans=LINF;
    rep(i,h){
        ans=min()
    }

    return 0;
}
/*
距離が同じますが斜めになってる。斜めの中の最小値を全部前計算しておくと各始点についての計算量が
4*H*定数くらいになって行ける？でも実装がだるすぎる。
各始点終点についてのテーブルを考えると10^12個の要素を持つことになるので確実にTLE
各列に上から順に等差数列{0,C,2C,...}を足していったもの、下から順に同じ等差数列を足していったものを
前計算する。これは計算量10^6くらいで出来る。またその時に、上から順番に値が小さかったものを
上からの長さごとに保存しておく。
上下左右から等差数列を足したやつと、4つの端から各長さまでで最小のものの値をメモっていけば多分10^6くらいで解けるけど
あまりにも実装がめんどくさすぎた。

*/