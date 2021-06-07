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
int n,m;
vector<int>vec[15];
int w[15];
int main(){
    cin>>n>>m;
    rep(i,m){
        int a;cin>>a;
        rep(j,a){
            int x;cin>>x;x--;vec[i].pb(x);
        }
    }
    rep(i,m)cin>>w[i];
    int ans=0;
    rep(i,(i<<n)){
        rep(j,m){
            int x=0;
            rep(k,vec[j].size()){
                int a=vec[j][k];
                if(((i>>a)&1)) x^=1;
            }
            if(x!=w[j])goto f;
        }
        ans++;f:;
    }
    cout<<ans<<endl;
    return 0;
}
//最強


/* #include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int,int>;

int main(){
    int n,m;cin>>n>>m;
    vector<int> k(m+1);
    vector<vector<int>> s(11,vector<int>(11));
    ll ans=0;
    bool flag=1;

    for(int i=1;i<=m;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>s[i][j];
        }
    }
    vector<int> p(m+1);
    for(int i=1;i<=m;i++){
        cin>>p[i];
    }



    for(int i=0;i<(1<<n);i++){
        int temp=(i<<1);
        flag=1;
        for(int j=1;j<=m;j++){
            int count0=0;
            for(int c=1;c<=k[j];c++){
                if((1<<s[j][c])&temp){
                    count0++;
                }
            }
            if(count0%2!=p[j])flag=0;
        }
        if(flag)ans++;
    }
    cout<<ans<<endl;
    
    return 0;
} */
//bit全探索