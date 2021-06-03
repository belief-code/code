#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int,int>;

int main(){
    ll n;cin>>n;
    for(int i=sqrt(n);i>0;i--){
        if(n%i==0){
            cout<<max(to_string(i).size(),to_string(n/i).size())<<endl;
            break;
        }
    }
    return 0;
}