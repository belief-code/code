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

vector<P>  macchi(vector<P> x){
    vector<P> y;
    rep(i,x.size()/2){
        y.pb(max(x[2*i],x[2*i+1]));
    }
    return y;
}

int main(){
    int n;cin>>n;
    vector<P> a(pow(2,n));
    rep(i,pow(2,n)){
        cin>>a[i].fi;
        a[i].sc=i;
    }

    while(a.size()>2){
        a=macchi(a);
    }
    P ans=min(a[0],a[1]);
    cout<<ans.sc+1<<endl;
    return 0;
}
//2^16=65536
//とりあえず普通に実装してみる。パット見多項式時間にするのはキツそう。
//input時に減らしてから配列に入れても良いかも
//TLEせずAC。かんたんすぎた