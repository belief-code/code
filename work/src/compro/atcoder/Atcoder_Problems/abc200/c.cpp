#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int n,temp;cin>>n;
    long long ans=0;
    vector<long long> a(200,0);
    for(int i=0;i<n;i++){
        cin>>temp;
        temp%=200;
        a[temp]++;
    }

    for(int i=0;i<200;i++){
        ans+=a[i]*(a[i]-1)/2;
    }

    cout<<ans<<endl;

    return 0;
}

//計算途中もint*intとかだとintで出されちゃうから注意