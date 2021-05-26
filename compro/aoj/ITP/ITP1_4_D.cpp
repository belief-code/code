#include<iostream>
using namespace std;

int main(){
    int N,Min,Max,t;
    long long Sum;
    cin>>N>>Min;
    Max=Min;
    Sum=Min;
    while(cin>>t){
        if(t<Min) Min=t;
        if(t>Max) Max=t;
        Sum+=t;
    }
    cout<<Min<<" "<<Max<<" "<<Sum<<endl;
    return 0;
}