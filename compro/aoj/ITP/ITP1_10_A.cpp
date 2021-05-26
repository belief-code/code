#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
    double x1,x2,y1,y2;
    cin>>x1>>x2>>y1>>y2;
    cout<<fixed<<setprecision(5)<<sqrt(pow(y1-x1,2) +pow(y2-x2,2))<<endl;
}