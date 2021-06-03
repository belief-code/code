#include<iostream>
using namespace std;

int main(){
    string x;cin>>x;
    for(int i=0;i<x.size();i++){
        if(x[i]=='.'){
            x.erase(i);
        }
    }

    cout<<x<<endl;
    
    return 0;
}