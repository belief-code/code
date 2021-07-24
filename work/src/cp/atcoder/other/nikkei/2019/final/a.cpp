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
    int n;cin>>n;
    vc<int> a(n);
    //累積和は区間を表す添字を持つべきなので,半開区間で定義すると良い.
    vc<ll> suma(n+1);
    rep(i,n){
        cin>>a[i];
        suma[i+1]=suma[i]+a[i];
    }

    srep(i,1,n+1){
        ll maxsum=0;
        rep(j,n-i+1){
            maxsum=max(maxsum,suma[j+i]-suma[j]);
        }
        cout<<maxsum<<endl;
    }
    return 0;
}

/*
愚直に累積和を用いた実装を考える.
各区間を与えたときの計算量はO(1)となる(累積和を用いる).
各kに対して,~n個のクエリに答える必要がある.
kはn通りあるので,結局O(n^2).ここでN<=3000であるのでこれは時間内に計算可能.
*/