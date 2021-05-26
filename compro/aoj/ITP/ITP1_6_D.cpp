#include<iostream>
#include<vector>
using namespace std;
#define rep(i,x) for(int i=0;i<(x);i++)

int main(){
    int n,m,temp;

    cin>>n>>m;    int mat[n][m]={};
    int vec[m]={};
    rep(i,n){
        rep(j,m) cin>>mat[i][j];
    }
    rep(i,m) cin>>vec[i];

    rep(i,n){
        temp=0;
        rep(j,m){
            temp+=mat[i][j]*vec[j];
        }
        cout<<temp<<endl;
    }
    return 0;
}