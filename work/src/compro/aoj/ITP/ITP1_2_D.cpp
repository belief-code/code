#include<iostream>
using namespace std;

int main(){
    int W,H,x,y,r;
    while(cin>>W>>H>>x>>y>>r){
        if(0<=x-r&&x+r<=W&&0<=y-r&&y+r<=H){
            cout<<"Yes"<<endl;
        }else{
            cout << "No" <<endl;
        }

    }
    return 0;
}