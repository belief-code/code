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
    int n,x;cin>>n>>x;
    int ans=-1,alc=0;
    bool flag=1;
    rep(i,n){
        int v,p;cin>>v>>p;
        alc+=v*p;
        if(alc>(x*100)&&flag){
            ans=i+1;
            flag=0;
        }
    }
    cout<<ans<<endl;
    return 0;
}

//double型ですら普通に切り捨て起こっておかしくなる。絶対に整数型で計算すべし。