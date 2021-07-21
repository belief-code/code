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
    int rq;cin>>rq;
    int q=100000;
    vc<int> like(q+1,0);
    vc<int> sumlike(q+1,0);
    srep(i,2,q+1){
        if(like[i]!=1){
            for(int j=2;j*i<=q;j++){
                like[i*j]=1;
            }
            if(i*2-1<=q&&like[i*2-1]==0){
                like[i*2-1]=2;
            }
        }
        sumlike[i]=sumlike[i-1];
        if(like[i]==2)sumlike[i]++;
    }
    rep(i,rq){
        int l,r;cin>>l>>r;
        cout<<sumlike[r]-sumlike[l-1]<<endl;
    }
    return 0;
}


/*
前計算出来ないとまずはきつそうなことは簡単にわかる。
前計算するにしても毎回素数か確認するのは時間怪しそう(多分いける)。
エラトステネスの篩みたいな感じで順番に計算していく。累積和使って終わり
*/