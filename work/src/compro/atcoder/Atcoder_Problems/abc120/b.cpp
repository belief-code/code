#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int,int>;

int main(){
    int a,b,k;cin>>a>>b>>k;
    int count=0,ans;
    for(int i=min(a,b);i>0;i--){
        if(a%i==0&&b%i==0){
            count++;
            ans=i;
        }
        if(count==k)break;
    }
    cout<<ans<<endl;
    return 0;
}