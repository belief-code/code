#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;cin>>n;
    ll ans=0;
    int temp;
    ll sum=0;
    vector<ll> a(n);
    rep(i,n){
        cin>>a[i];
        ans+=(n-1)*a[i]*a[i];
        sum+=a[i];
        ans-=(-2)*a[i]*sum;
    }
    rep(i,n){
        ans+=(-2)*a[i]*sum;
    }

    cout<<ans<<endl;
    return 0;
}

//上は数学的解法
//解説によるとAi-Ajの絶対値のパターンがAの制約から200くらいしかないからこれでいける。
//どこかにパターン数のボトルネック的なものがないか確認すれば気づけそう。