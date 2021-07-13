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
    int m;cin>>m;
    vp sign(m);
    sign[0].fi=0;
    sign[0].sc=0;
    P gosa;cin>>gosa.fi>>gosa.sc;
    srep(i,1,m){
        cin>>sign[i].fi>>sign[i].sc;
        sign[i].fi-=gosa.fi;
        sign[i].sc-=gosa.sc;
    }
    int n;cin>>n;
    map<P,bool> sky;
    vp realsky(n);
    rep(i,n){
        int x,y;cin>>x>>y;
        realsky[i]=mp(x,y);
        sky[mp(x,y)]=1;
    }

    rep(i,n){
        P start=realsky[i];
        srep(j,1,m){
            if(!sky[mp(start.fi+sign[j].fi,start.sc+sign[j].sc)])break;
            if(j==m-1){
                cout<<start.fi-gosa.fi<<" "<<start.sc-gosa.sc<<endl;
                return 0;
            }
        }
    }
    return 0;
}