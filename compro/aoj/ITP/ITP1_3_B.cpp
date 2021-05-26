#include<iostream>
using namespace std;

int main(){
    int a,i;
    i=0;
    while(cin>>a){
        i++;
        if(a==0){
            break;
        }
        cout <<"Case "<<i<<": "<<a<<endl;
    }
    return 0;
}