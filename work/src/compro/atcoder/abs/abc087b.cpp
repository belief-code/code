#include<iostream>
#include<vector>
using namespace std;

int main(){
    int a,b,c,x;cin>>a>>b>>c>>x;
    long long ans=0;
    for(int i=0;i<=a;i++){
        if(500*i>x) break;
        for(int j=0;j<=b;j++){
            if(500*i+100*j>x) break;
            for(int k=0;k<=c;k++){
                if(500*i+100*j+50*k==x){
                    ans++;
                    break;
                }
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}

//3重ループだけどインプット少ないから行けるかも→いけた
