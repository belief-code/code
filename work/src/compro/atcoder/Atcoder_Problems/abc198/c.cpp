#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    long long r,x,y;cin>>r>>x>>y;
    long long rbegin;
    bool flag=0;
    rbegin=(float)(pow(x*x+y*y,0.5))/r;
    if(x==0&&y==0){
        cout<<0<<endl;
        goto end;
    }else if(x*x+y*y<r*r){
        cout<<2<<endl;
        goto end;
    }
        if(((rbegin-1)*(rbegin-1)*r*r)>=x*x+y*y) cout<<rbegin-1<<endl;
        else if((rbegin*rbegin*r*r)>=x*x+y*y) cout<<rbegin<<endl;
        else if(((rbegin+1) * (rbegin+1) * r * r) >= x * x + y * y)cout << rbegin+1 << endl;
        else cout<<rbegin+2<<endl;
    end:
    return 0;
}