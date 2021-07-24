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
const ll mod = 100000;

int main(){
    int n,m;cin>>n>>m;
    vc<int> s(n-1);
    vc<ll> sum(n,0);
    rep(i,n-1){
        cin>>s[i];
        sum[i+1]=sum[i]+s[i];
    }
    int from=0;
    ll ans=0;
    rep(i,m){
        int to;cin>>to;
        to+=from;
        ans+=abs(sum[to]-sum[from]);
        from=to;
    }
    cout<<ans%mod<<endl;

    return 0;
}


/*
超簡単そう.累積和を持っておいて,数列からfromとtoをそれぞれ求めてabs(sum[to]-sum[from])をループの中で答えに足し合わせて行けば良さそう.問題はabsを使えるかの判定くらい(普通に条件分岐してもいい).移動距離の合計はどんなに頑張っても10^18超えなさそうだから最後に割ってOK.
*/