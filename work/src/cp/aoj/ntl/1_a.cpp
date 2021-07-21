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
    int tn=n;
    vc<int> ans;
    srep(i,2,sqrt(tn)+1){
        while(n%i==0){
            n/=i;
            ans.pb(i);
        }
    }
    if(n==tn){
        cout<<n<<": "<<n<<endl;
        return 0;
    }
    cout<<tn<<":";
    rep(i,ans.size()){
        cout<<" "<<ans[i];
    }
    if(n==1)cout<<endl;
    else cout<<" "<<n<<endl;
    return 0;
}

/*
整数nがある約数pを持つ時、同時にn/pを約数に持つ。このことから、素数である場合には、
nは√nより大きい約数を持つことはない(自分自身を除く)
よってO(√n)で計算可能。ここで、n<=10^9より√n<=10^(9/2)<~10^5なので時間内に計算可能
*/

/*
バロラントやりながらだから問題文読み間違いしまくってた。
この問題での大事なことは一つで、√nより大きな素因数は一つしか存在し得ない(2つあるとすると積がnを超える)
*/