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

int main(){
    ll m,n;cin>>m>>n;
    ll ans=1;
    while(n>0){
        if(n&1)(ans*=m)%=mod;
        (m*=m)%=mod;
        n>>=1;
    }
    cout<<ans<<endl;
    return 0;
}

/*
n回積を取るとTLEするので,高速な冪乗計算を行う.
nを2進数表記して,下から順にビットを見ていくことを行う.このときそのような走査の回数はO(logn)となる.
また見ていく時にそのbitに対応する冪乗の値を持っておくことで,
a^(b+c)=a^b*a^cの関係より実際に求めたい値を求めることが出来る.
*/