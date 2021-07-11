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
const ll mod = 1000000007;


int main(){
    int n;cin>>n;
    vi h(n);
    rep(i,n){
        cin>>h[i];
    }
    if(n==1){
        cout<<h[0]<<endl;
        return 0;
    }
    vv<ll> dp(n+1,vl(n+1,LINF));
    //初期化(要素数0,1で初期化)
    rep(i,n){
        if(i==0)dp[i][i+1]=h[i]+h[i+1];
        else if(i==n-1)dp[i][i+1]=h[i-1]+h[i];
        else dp[i][i+1]=h[i-1]+h[i]+h[i+1];
        dp[i][i+1]%=mod;
        dp[i][i]=0;
    }
    dp[n][n]=0;
    srep(i,2,n+1){
        //区間内の要素数i(2ton)
        rep(l,n){
            srep(r,l,n+1){
                if(r-l>i)break;
                srep(k,l,r){
                    if(k==l||k==r-1){
                        dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]+h[k]*2);
                    }else dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]+h[k]*3);
                }
            }
        }
    }
    cout<<dp[0][n]<<endl;
    return 0;
}
//最後に切る木について考えると左右をそれぞれの最善コスト(最後に切る木が残ってないと仮定したときの)+最後の木のコスト×3
//左右それぞれの最善コストは両端が高さ0の木と仮定すると(この過程をしてマージ操作の時に一回分足せばいい)
//この中のどれかが最後に切られたとすると左右それぞれの最善コスト(最後に切る木が残ってないと仮定したとき)+最後の木のコスト×3
//dp[l][r]:=[l,r)の区間の最善コスト(高さ0で囲まれていると仮定する)
//なんかTLEしそう。めっちゃしそうだけどまあいいか
//これP数える問題だったけどちょっと変えればそれは計算可能