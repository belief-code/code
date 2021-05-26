#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
    double a,b,C;
    cin>>a>>b>>C;
    C *= M_PI/180;
    cout<<fixed<<setprecision(5);
    cout<<0.5*a*b*sin(C)<<endl;
    cout<<a+b+sqrt(a*a+b*b-2*a*b*cos(C))<<endl;
    cout<<b*sin(C)<<endl;
    return 0;
    
}