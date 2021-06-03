#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;cin>>n;
    bool flag=0;
    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++){
            if(i*j==n) flag=1;
        }
    }
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}