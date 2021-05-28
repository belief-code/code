#include<iostream>
#include<string>
using namespace std;

int main(){
    while(1){
        int sum=0;
        string str;
        cin>>str;
        if(str=="0") break;
        for(int i=0;i<str.size();i++) sum+=str[i]-'0';
        cout<<sum<<endl;
    }
    return 0;
}