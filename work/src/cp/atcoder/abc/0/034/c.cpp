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
const ll mod=1000000007;

ll inverse(ll a){
    ll ret=1,index=mod-2;
    while(index>0){
        if(index&1)(ret*=a)%=mod;
        (a*=a)%=mod;
        index>>=1;
    }
    return ret;
}

int main(){
    int w,h;cin>>w>>h;
    ll ans=1;
    rep(i,w-1){
        (ans*=(w+h-2-i))%=mod;
        (ans*=inverse(i+1))%=mod;
    }
    cout<<ans<<endl;
    return 0;
}

/*
(i,j)に移動する通り数をdp[i][j]と置くと,
dp[i][j]=dp[i-1][j]+dp[i][j-1];と漸化式を立てられる.各要素の計算にO(1)でマス目が10^5*10^5なのでTLEする.なのでこの方針はだめ.(工夫すると多分出来る(原点から順に二回移動したマスを埋めていってW,hの偶奇で最後詰めるみたいなかんじ(更にこの操作を繰り返しやると二分法みたいな感じになって高速に求められそう(これを行列累乗という？))))
次の方針を考える.これは上方向の移動と右方向の移動をそれぞれ(W-1),(H-1)回行う場合の数のようなものなので,(W+H-2)C(W-1)が求める値になる.問題の条件の下でa/b=x⇔a=x*bより,xについてa/b≡x⇔a≡x*b⇔a*b^(-1)≡x.ここでb^(-1)はbの逆元(右辺では逆元が打ち消し合う).
ここでlog(10^9)~30なので,コンビネーションの分母に相当する部分の逆元をW個求めるのにW*30<~10^7位時間が必要.コンビネーションの分子については,一回一回の積が定数時間で終わるので大丈夫.これなら耐えられそう.コンビネーションを階乗に分解すると早く解けそうな気もするけど一問目だからかなり愚直にやってみる.
*/