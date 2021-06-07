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
    int n,m,ans=0;cin>>n>>m;
    vector<int> boxn(n);
    rep(i,n)boxn[i]=i;
    vector<P> edge(m);
    rep(i,m){
        cin>>edge[i].fi>>edge[i].sc;
        edge[i].fi--;
        edge[i].sc--;
    }
    do{
        int flag=1;
        rep(i,n-1){
            flag=1;
            rep(j,m){
                if(edge[j].fi==min(boxn[i],boxn[i+1])&&edge[j].sc==max(boxn[i],boxn[i+1])){
                    flag=0;
                }
            }
            if(flag)break;
        }
        if(flag)continue;
        else ans++;
    }while(next_permutation(boxn.begin()+1,boxn.end()));
    cout<<ans<<endl;
    return 0;
}
/* 目的のエッジが存在するかどうかの判定が冗長だったけど始点の数と終点の数が
限られているので二重配列で箱を作ってbox[i][j]==1ならばiからjに通じるエッジが
存在するというような感じにするとキレイに判定できる。 */