#include<iostream>
using namespace std;

int main(){
    int n;cin>>n;
    int a,b;cin>>a>>b;
    long long ans=0;

    for(int j=1;j<=n;j++){
        int sum=0;
        int i=j;

        while(i!=0){
            sum+=i%10;
            i/=10;
        }
        if(a<=sum&&sum<=b){
            ans+=j;
        }
    }

    cout<<ans<<endl;

    return 0;
}