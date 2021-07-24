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
    int n,m;cin>>n>>m;
    vc<ll> table(n,0);
    int from;
    cin>>from;
    from--;
    rep(i,m-1){
        int to;cin>>to;
        to--;
        if(from<to){
            table[from]++;
            table[to]--;
        }else{
            table[to]++;
            table[from]--;
        }
        from=to;
    }
    ll ans=0;
    ll now=0;
    rep(i,n-1){
        ll a,b,c;cin>>a>>b>>c;
        now+=table[i];
        ans+=min(a*now,c+b*now);
    }
    cout<<ans<<endl;
    return 0;
}

/*
順番は実際関係ないので,各鉄道を何回使うのかがわかれば,それをICカードを使うべきかどうかだけ判定して足し合わせれば答えが求まる.
愚直にそれを行うと,10^10でTLEする.いもす法を用いるとO(M+N)でいける.
*/