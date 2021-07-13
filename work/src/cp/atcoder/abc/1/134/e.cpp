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
#define pf push_front
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
    int n;cin>>n;
    vi a(n);
    rep(i,n){
        cin>>a[i];
    }
    deque<int> deq;
    deq.pf(a[0]);
    srep(i,1,n){
        int k=lower_bound(rng(deq),a[i])-deq.begin();
        if(k==0)deq.pf(a[i]);
        else deq[k-1]=a[i];
    }
    cout<<deq.size()<<endl;
    return 0;
}

//1.問題の読み替え:狭義単調増加部分列に分けるときの最小個数を求めよ
//2.操作段階:同じ色を一気に塗る、前から順番に塗り分けていくの二通り
//3.切り口:最初から順番に塗り分ける一般的な方法から試す。
//3段階目までとりあえず考える。
//21453のとき
//2:どのように塗っても良いので0で塗る
//1:0で塗れないので消去法的に1で塗る
//4:0か1で塗る、または新しく2で塗るパターンがある
//0か1で塗る場合は当然0で塗ったほうがベターなので(部分列の最後の数値が1で塗ると悪くなる)0で塗ったほうがいい
//新しく2で塗る場合を0で塗る場合と比較すると、最終形で考えると2で塗ったパターンでの最終形で色2の数列の4以降の数列を
//色0で塗られた2よりも後の数列と交換することで解を悪化させずに変形出来るので、0で塗るほうがベターである。
//よって0で塗ると良い。
//このことは各操作段階においても言えるので、一般化すると、
//そこまでに作ってきた部分列の最後尾の中で今見ている値よりも小さい中で最も大きいものの後にアタッチする。
//そのようなものがなければ新しく部分列を作る。
//このような操作を行う上で保持する必要のあるデータは各部分列の最後尾の値のみであるから
//そのようなデータを持つことを考える。
//ここでアタッチするべき部分列を探すのは二分探索によって行えるので計算量が落ちる。
//新しく作る部分列を配列の先頭に作ることで配列が広義単調増加になりlower_boundを使うことが出来るので
//dequeもしくはmultisetを用いると良い。