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
    int n,count=1,indp,indq;cin>>n;
    vector<int> nv(n);
    rep(i,n)nv[i]=i+1;
    vector<int> p(n);
    vector<int> q(n);
    rep(i,n)cin>>p[i];
    rep(i,n)cin>>q[i];
    do{
        if(nv==p)indp=count;
        if(nv==q)indq=count;
        count++;
    }while(next_permutation(nv.begin(),nv.end()));
    cout<<abs(indp-indq)<<endl;
    return 0;
}