#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    int maxa=0;
    int minb=2000;

    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>maxa) maxa=a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        if(b[i]<minb) minb=b[i];
    }
    if(minb-maxa+1<0)cout<<0<<endl;
    else  cout<<minb-maxa+1<<endl;


}