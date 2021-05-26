#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;cin>>n;
    vector <int> a(n+1);
    vector <int> b(n+1);
    vector <int> c(n+1);
    vector <int> boxa(n+1,0);
    long ans=0;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        boxa[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }

    for(int i=1;i<=n;i++){
        ans+=boxa[b[c[i]]];
    }
    cout<<ans<<endl;
}