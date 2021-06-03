#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int,int>;

int main(){
    int a,b;cin>>a>>b;
    double ans=(double)((a-b)*100.0/(a*1.0));
    cout<<ans<<endl;
    return 0;
}