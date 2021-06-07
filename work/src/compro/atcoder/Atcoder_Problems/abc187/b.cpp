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
    ll ans=0;
    vector<P> pos(n);
    rep(i,n){
        cin>>pos[i].fi>>pos[i].sc;
    }
    
    rep(i,n){
        for(int j=i+1;j<n;j++){
            if(abs(pos[i].sc-pos[j].sc)<=abs(pos[i].fi-pos[j].fi)){
                ans++;
                //cout<<i<<' '<<j<<endl;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
//数学的にやりたくなかったけどllの除算でdoubleにキャストすると多分エッジケース存在するから
//両辺に分母掛けて整数の比較にしたけど分母が負の時に場合分け必要でだるかったから
//傾きの絶対値を上から抑えた。