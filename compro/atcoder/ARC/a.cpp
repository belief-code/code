#include<iostream>
#include<vector>
#include<numeric>
using namespace std;


int main(){
    int n;cin>>n;
    vector<long long> a(n);
    vector<long long> tempk(n+1);
    vector<int> maxink(n+1);
    maxink[0]=0;
    long long temp=0;
    tempk[0]=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(maxink[i]<a[i]){
            maxink[i+1]=a[i];
        }else{
            maxink[i+1]=maxink[i];
        }
        temp+=a[i];
        tempk[i+1]=tempk[i]+temp;
    }



    for(int i=0;i<n;i++){
        cout<<tempk[i+1]+maxink[i+1]*(i+1)<<endl;
    }
}