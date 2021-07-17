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
    int v,e;cin>>v>>e;
    vvi g(v,vi(v,INF));
    rep(i,e){
        int s,t,d;cin>>s>>t>>d;
        g[s][t]=d;
    }
    //概算すると結構ギリギリだったからintじゃなくてllにする
    vv<ll> d(v,vl(v,LINF));
    //初期化(これループ内でもうまいことやれば条件噛ませずに出来る？)
    rep(i,v){
        rep(j,v){
            if(g[i][j]==INF)continue;
            d[i][j]=g[i][j];
        }
    }
    //経由可能頂点は0からiまで
    rep(i,v){
        //始点j
        rep(j,v){
            //終点k
            rep(k,v){
                //各ループでd[j][i],d[i][k]が参照されるが、
                //この値はi番目のループ内で更新されないので更新が終わるまで保存する必要とか前計算するとかはしなくていい
                if(d[j][i]==LINF||d[i][k]==LINF)continue;
                d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
            }
        }
    }
    //閉路の確認
    int flag=0;
    rep(i,v){
        rep(j,v){
            if(d[i][j]+d[j][i]<0)flag=1;
        }
    }
    if(flag){
        cout<<"NEGATIVE CYCLE"<<endl;
        return 0;
    }
    rep(i,v){
        rep(j,v){
            if(i==j)cout<<0;
            else if(d[i][j]==LINF)cout<<"INF";
            else cout<<d[i][j];
            if(j==v-1&&i==v-1)cout<<endl;
            else if(j==v-1)cout<<"\n";
            else cout<<" ";
        }
    }
    return 0;
}


/*考察
テーブルを埋める問題。(operational_problems参照)
これはテーブルの各更新が各要素について定数時間で終わるので、
O(V^3)で計算可能でこれはTLEしない。
負閉路の存在確認は各最短経路について逆の最短経路との和が負になるような要素がないか確認すれば良い。
これはO(V^2)で可能
if(d[j][i]==LINF||d[i][k]==LINF)continue;
この条件文入れなかったせいで、d[j][i]==LINFに負の数d[i][k]足されてバグった。
そもそもそのパターンはまず考えるべきだったし、実際にコンテスト中とかなら計算量別に定数倍になるだけだから
とりあえず条件文入れといたほうがいい
*/

/*AC後感想
テーブルを埋める問題は天下り的に解法の良さが示されるから考察の余地があまりない。
あるとすれば、状態遷移のキーを経由可能ノードにするのはなぜ？ってところくらい。
これは単純にキーとしてふさわしそうなパラメーターがこれくらいしかないことによるものとしか言えない。
これをキーとして回そうとした時にテーブルの更新が各要素について定数時間で出来るじゃん！ってあとから
計算量が少ないことがわかる系だからね。先に計算量が少ない更新手順から思いつくのは相当きついと思う。
ってかほぼ無理かな～。割り算を掛け算から超短時間で計算するようなもん
*/