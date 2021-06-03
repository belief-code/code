#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;cin>>t;
    for(int pine=0;pine<t;pine++){
        int n,m=0;cin>>n;
        vector<int> p(n+1,0);
        for(int i=0;i<n;i++){
            cin>>p[i];
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n-i;j++){
                if(i!=0&&(n-i)%2==1&&j==0) j++;

            }
        }
        


    }
}