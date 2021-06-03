#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int,int>;
#define INF 10000000

int main(){
    int n,ans;cin>>n;
    vector<P> quea(n);
    vector<P> queb(n);
    rep(i,n){
        cin>>quea[i].first>>queb[i].first;
        quea[i].second=i;
        queb[i].second=i;
    }
    sort(quea.begin(),quea.end());
    sort(queb.begin(),queb.end());
    if(quea[0].second==queb[0].second){
        ans=min(quea[0].first+queb[0].first,min(max(quea[0].first,queb[1].first),max(quea[1].first,queb[0].first)));
    }else ans=max(quea[0].first,queb[0].first);

    cout<<ans<<endl;
}
//総当りでも行けてそっちのほうが実装自体は簡単