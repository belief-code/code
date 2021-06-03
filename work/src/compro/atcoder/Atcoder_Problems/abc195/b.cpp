#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int,int>;

int main(){
    int a,b,w;cin>>a>>b>>w;
    w*=1000;
    int ans1,ans2,flag=1;
    if((w/a)*b<w)flag=0;
    else{
        ans1=(w+b-1)/b;
        ans2=w/a;
    }
    if(flag) cout<<ans1<<" "<<ans2<<endl;
    else cout<<"UNSATISFIABLE"<<endl;
    return 0;
}