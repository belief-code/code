#include<iostream>
using namespace std;
#define rep(i,x) for(int i=0;i<(x);i++)

int main(){
    int r,c;
    cin>>r>>c;
    int matrix[r+1][c+1]={};
    rep(i,r){
        rep(j,c){
            cin>>matrix[i][j];
            matrix[i][c]+=matrix[i][j];
            matrix[r][j]+=matrix[i][j];
            matrix[r][c]+=matrix[i][j];
        }
    }
    rep(i,r+1){
        rep(j,c+1){
            if(j==c&&i==r){
                cout<<matrix[i][j]<<endl;
                break;
            }
            if(j==c){
                cout<<matrix[i][j]<<endl;
                continue;
            }
            cout<<matrix[i][j]<<' ';
        }
    }
    return 0;
}