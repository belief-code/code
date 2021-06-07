#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

int main(){
    int n;cin>>n;
    int ans=0;
    vector<P> test[n];
    rep(i,n){
        int a;cin>>a;
        rep(j,a){
            int tmpx,tmpy;
            cin>>tmpx>>tmpy;
            tmpx--;
            test[i].pb(mp(tmpx,tmpy));
        }
    }
    rep(i,(1<<n)){
        int flag=1;
        rep(j,n){
            int tmp=!((i>>j)&1);//j番目が嘘つきなら1
            if(tmp) continue;
            int size=test[j].size();
            rep(k,size){
                int test11=tmp^test[j][k].sc;
                int test12=(i>>(test[j][k].fi))&1;
                if(test11!=test12)flag=0;
            }
        }
        if(flag)ans=max(ans,__builtin_popcount(i));
    }
    cout<<ans<<endl;
    return 0;
}

//bit全探索。真偽不明を絶対に嘘をつくだと思って実装したせいで終わった。
//通らなかったら問題をよく読もう。