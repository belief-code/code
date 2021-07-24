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
const int oneday=86400;

int converter(string s){
    int ret=0;
    ret+=(s[0]-'0')*3600*10+(s[1]-'0')*3600;
    ret+=(s[3]-'0')*60*10+(s[4]-'0')*60;
    ret+=(s[6]-'0')*10+(s[7]-'0');
    return ret;
}

void solver(int n){
    vc<int> table(oneday+1,0);
    rep(i,n){
        string s,t;cin>>s>>t;
        table[converter(s)]++;
        table[converter(t)]--;
    }
    int ans=0;
    int nownum=0;
    rep(i,oneday){
        nownum+=table[i];
        ans=max(ans,nownum);
    }
    cout<<ans<<endl;
}
int main(){
    while(1){
        int n;cin>>n;
        if(n==0)break;
        solver(n);
    }
}

/*
一番多く同時に走っているときの走っている列車の数を数えれば良い.
これはいもす法を用いれば簡単に求められる(計算時間86400+10000程度).
*/