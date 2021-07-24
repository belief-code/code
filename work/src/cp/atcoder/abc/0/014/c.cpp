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
const int value=1000001;

int main(){
    int n;cin>>n;
    vc<int> table(value+1,0);
    rep(i,n){
        int a,b;cin>>a>>b;
        table[a]++;
        table[b+1]--;
    }
    int ans=0;
    int nowval=0;
    rep(i,value){
        nowval+=table[i];
        ans=max(ans,nowval);
    }
    cout<<ans<<endl;
    return 0;
}

/*
いもす法.
*/