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
    int n,m;cin>>n>>m;
    ll ans=0;
    vector<vector<int>> cond(m,vector<int>(2));
    rep(i,m){
        cin>>cond[i][0]>>cond[i][1];
        cond[i][0]--;
        cond[i][1]--;
    }
    int k;cin>>k;
    vector<vector<int>> sel(k,vector<int>(2));
    rep(i,k){
        cin>>sel[i][0]>>sel[i][1];
        sel[i][0]--;
        sel[i][1]--;
    }

    rep(i,(1<<k)){
        ll count=0;
        vector<bool> dish(n,0);
        rep(j,k){
            dish[sel[j][(i>>j)&1]]=1;
        }
        
        rep(j,m){
            if(dish[cond[j][0]]&&dish[cond[j][1]])count++;
        }
        ans=max(ans,count);
    }
    cout<<ans<<endl;
    return 0;
}
//人がどっちに置くかでbit全探索
//さいこう！