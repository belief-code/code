#include<bits/stdc++.h>
#define pu push
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define rrep(i,x) for(int i=1;i<=x;i++)
#define drep(i,n) for(int i = (n)-1; i >= 0; i--)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define BITSC(x,v) (binary_search(x.begin(),x.end(),v)
#define dup(x,y) (((x)+(y)-1)/(y))
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;
int getInt(){int x;scanf("%d",&x);return x;}
template<typename T>istream& operator>>(istream&i,v(T)&v){rep(j,sz(v))i>>v[j];return i;}
const double eps =1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}

int main(){
    int r,c;cin>>r>>c;
    ll ans=0;
    vector<vector<bool>> num(r,vector<bool>(c,0));
    rep(i,r){
        rep(j,c){
            bool tmp;cin>>tmp;
            num[i][j]=tmp;
        }
    }


    rep(i,(1<<r)){
    vi omote(c,0);
        rep(j,r){
            if((1<<j)&i){
                rep(k,c){
                    omote[k]+=1^num[j][k];
                }
            }else{
                rep(k,c){
                    omote[k]+=num[j][k];
                }
            }
        }
        ll tempans=0;
        rep(j,c){
            tempans+=max(omote[j],r-omote[j]);
        }
        ans=max(tempans,ans);
    }
    cout<<ans<<endl;
    return 0;
}