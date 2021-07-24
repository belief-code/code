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


int main(){
    int n,m,q;cin>>n>>m>>q;
    vv<int> lrmap(n,vc<int>(n,0));
    rep(i,m){
        int tmpl,tmpr;cin>>tmpl>>tmpr;
        lrmap[--tmpl][--tmpr]++;
    }
    vv<int> lrmapsum(n+1,vc<int>(n+1,0));
    rep(i,n){
        rep(j,n){
            lrmapsum[i+1][j+1]=lrmapsum[i+1][j]+lrmapsum[i][j+1]-lrmapsum[i][j]+lrmap[i][j];
        }
    }
    rep(i,q){
        int a,b;cin>>a>>b;
        a--;b--;
        cout<<lrmapsum[n][b+1]-lrmapsum[a][b+1]<<endl;
    }
    return 0;
}

/*
注意:列車は始点と終点が同じ場合がある.クエリ10^5.
LとRを縦軸横軸に持つ表を作って,列車の区間と表の位置を対応させていくことを考える.
この時,(p,q)によって二次元区間を適切にあらわすと区間内の要素数と求める列車の本数を対応させることができる.
また,二次元累積和を用いると良いが,Nが500以下なので,これは時間内に実現可能.
左下始点の表だとして,累積和をいい感じの隅から取っていくと無駄な計算とかしなくても良くなるけど,累積和を取る時に間違えそうだからやめておく.
*/