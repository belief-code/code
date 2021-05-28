#include<iostream>
using namespace std;

int main(){
    int a,b,t;
    while(cin>>a>>b){
        if(a==0&&b==0){
            break;
        }
        if(a>b){
            cout<<b<<" "<<a<<endl;
        }else{
            cout<<a<<" "<<b<<endl;
        }
    }
    return 0;
}