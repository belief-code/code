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
    double count=0.0;
    double ans=0.0;
    vector<P> pos(n);
    rep(i,n){
        cin>>pos[i].fi>>pos[i].sc;
    }
    SORT(pos);
    do{
        rep(i,n-1){
            ans+=sqrt((pos[i+1].fi-pos[i].fi)*(pos[i+1].fi-pos[i].fi)+(pos[i+1].sc-pos[i].sc)*(pos[i+1].sc-pos[i].sc));
        }
        count++;
    }while(next_permutation(pos.begin(),pos.end()));
    ans/=count;
    cout<<fixed<<setprecision(15)<<ans<<endl;
    return 0;
}