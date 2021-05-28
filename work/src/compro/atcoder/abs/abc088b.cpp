#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n,ans=0;cin>>n;
    vector <int> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a.begin(),a.end());
    
    int ban=1;
    for(int i=0;i<n;i++){
        ans+=ban*a[a.size()-1];
        a.pop_back();
        ban*=-1;
    }

    cout<<ans<<endl;

    return 0;
}
