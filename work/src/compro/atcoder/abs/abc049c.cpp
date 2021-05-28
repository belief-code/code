#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;cin>>s;
    string a="dream",b="dreamer",c="erase",d="eraser";
    bool flag=0;

    while(s.size()>7){
        if(s.substr(s.size()-5,5)==a){
            s=s.substr(0,s.size()-5);
        }else if(s.substr(s.size()-7,7)==b){
            s=s.substr(0,s.size()-7);
        }else if(s.substr(s.size()-5,5)==c){
            s=s.substr(0,s.size()-5);
        }else if(s.substr(s.size()-6,6)==d){
            s=s.substr(0,s.size()-6);
        }else{
            flag=0;
            break;
        }
    }

if(s==a||s==b||s==c||s==d||s==""){
    flag=1;
}

if(flag) cout<<"YES"<<endl;
else cout<<"NO"<<endl;


    return 0;
}