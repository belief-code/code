#include<iostream>
using namespace std;

int main(){
    int n,y,flag=0;cin>>n>>y;


    for(int i=0;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            if(i*10000+j*5000+(n-i-j)*1000==y&&flag==0){
                cout<<i<<' '<<j<<' '<<n-i-j<<endl;
                flag=1;
            }
        }
    }
    if(flag==0)cout<<"-1 -1 -1"<<endl;

    return 0;
}