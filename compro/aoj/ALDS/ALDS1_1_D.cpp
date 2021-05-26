#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int n;cin>>n;
    vector <int> r(n);
    for(int i=0;i<n;i++){
        cin>>r[i];
    }
    int minr,ans;
    minr=r[0];
    ans=r[1]-minr;

    for(int i=1;i<n;i++){
       ans=max(ans,r[i]-minr);
       minr=min(minr,r[i]); 
    }
    cout<<ans<<endl;

}

//i=0のときだけ場合分けしないでもINT_MAX使えばいける。でもlimitインクルードしないといけない。