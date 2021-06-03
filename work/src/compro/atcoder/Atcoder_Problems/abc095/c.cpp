#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int,int>;

int main(){
    ll a,b,c,x,y;cin>>a>>b>>c>>x>>y;
    ll ans=x*a+y*b;
    for(int i=0;i<=2*max(x,y);i+=2){
        ll tempx=x,tempy=y;
        tempx-=i/2;
        tempy-=i/2;
        if(tempx<0)tempx=0;
        if(tempy<0)tempy=0;

        if(ans>tempx*a+tempy*b+i*c){
            ans=tempx*a+tempy*b+i*c;
        }
    }
    cout<<ans<<endl;
    return 0;
}