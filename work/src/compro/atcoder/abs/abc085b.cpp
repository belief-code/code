#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,temp,ans=0;cin>>n;
    vector <bool> box(101,false);

    for(int i=0;i<n;i++){
        cin>>temp;
        box[temp]=true;
    }

    for(int i=1;i<101;i++){
        if(box[i]==true) ans++;
    }

    cout<<ans<<endl;

    return 0;
}