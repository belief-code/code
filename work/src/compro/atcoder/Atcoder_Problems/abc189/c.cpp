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
    ll ans=0,mina;
    vector<ll> orange(n);
    rep(i,n){
        cin>>orange[i];
    }
    
    rep(i,n){
        mina=orange[i];
        for(int j=i;j<n;j++){
            mina=min(mina,orange[j]);
            ans=max(ans,mina*(j-i+1));
        }    
    }

    cout<<ans<<endl;

    return 0;
}
//二点選んで全探索は超ギリギリ、xの値で全探索→xの値でDP？
//二点選んで全探索の超ギリギリでとりあえず一回実装。
//AC→C問題なのに簡単すぎて考えすぎた。