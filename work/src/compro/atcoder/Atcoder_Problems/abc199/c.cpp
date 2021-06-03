#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int n;cin>>n;
    string s,temp1,temp2;cin>>s;
    temp1=s.substr(0,n);
    temp2=s.substr(n,n);
    int q;cin>>q;
    int t,a,b,count=1;

    for(int i=0;i<q;i++){
        cin>>t>>a>>b;

        if(t==1){
            if(count==1){
                swap(a<n+1?temp1[a-1]:temp2[a-n-1],b<n+1?temp1[b-1]:temp2[b-n-1]);
            }else{
                swap(a<n+1?temp2[a-1]:temp1[a-n-1],b<n+1?temp2[b-1]:temp1[b-n-1]);
            }
        }else if(t==2){
            count*=-1;
        }
    }

    cout<<(count==1?temp1+temp2:temp2+temp1)<<endl;

    return 0;
}
//substrの処理が長いから何とかする必要がある
//これでも通るけどsをtemp1temp2に分解しないでも行ける。必要手順をへらすことを常に考える。
//実は上の様にやってもswap(temp1,temp2)はo(1)で行えるので(これは多分参照先のswapを行っているから。)
//このことを使えばcountの値で場合分けする必要はなかった。
