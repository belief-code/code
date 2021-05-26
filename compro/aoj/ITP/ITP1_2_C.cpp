#include<iostream>
using namespace std;

int main(){
    int a,b,c,t;
    cin >>a>>b;
    if(b<a){
        t=a;
        a=b;
        b=t;
    }
    cin >>c;
    if(c<a){
        t=c;
        c=b;
        b=a;
        a=t;
    }else if(c<b){
        t=c;
        c=b;
        b=t;
    }
    cout << a << " " << b << " " << c << endl;
    return 0;
}