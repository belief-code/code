#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;cin>>n;
    int a,p,x;
    int ans=1000000001;
    rep(i,n){
        cin>>a>>p>>x;
        x-=a;
        if(x>0&&ans>p)ans=p;
    }
    if(ans==1000000001)cout<<"-1"<<endl;
    else cout<<ans<<endl;
    return 0;
}