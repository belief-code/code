#include<iostream>
using namespace std;

int main(){
    int n,k;cin>>n>>k;
    long long ans;
    ans=n;

    for(int i=0;i<k;i++){
        if(ans%200==0) ans/=200;
        else ans=ans*1000+200;
    }

    cout<<ans<<endl;

    return 0;
}