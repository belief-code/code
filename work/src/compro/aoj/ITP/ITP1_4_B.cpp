#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
    double r;
    while(cin>>r){
        cout<<fixed<<setprecision(6)<<M_PI*r*r<<" "<<2*M_PI*r<<endl;
    }
    return 0;
}