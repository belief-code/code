#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<bitset>
using namespace std;

int main(){
    int n;cin>>n;
    vector<long> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long ans=100000000000;
    vector<long> temp(1,0);

    for(int bit=0;bit<(1<<n-1);++bit){
        int count=0;
        temp.clear();
        temp.push_back(0);
        for(int i=0;i<n;i++){
            temp[count]|=a[i];

            if(bit&(1<<i)){
                count++;
                temp.push_back(0);
            }
        }
        while(temp.size()!=1){
            temp[0]^=temp[1];
            temp.erase(temp.begin()+1);
        }
        if(temp[0]<ans) ans=temp[0];
    }
    
    cout<<ans<<endl;

    return 0;
}

//bit全探索