#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;cin>>s;
    int a=0,b=0;

    for(int i=0;i<10;i++){
        if(s[i]=='o') a++;
        if(s[i]=='?') b++;
    }

    if(a==0) cout<<b*b*b*b<<endl;
    if(a==1) cout<<(b+1)*(b+1)*(b+1)*(b+1)-b*b*b*b<<endl;
    if(a==2) cout<<(b+2)*(b+2)*(b+2)*(b+2)-2*((b+1)*(b+1)*(b+1)*(b+1)-b*b*b*b)-b*b*b*b<<endl;
    if(a==3) cout<<(b+3)*(b+3)*(b+3)*(b+3)-b*b*b*b-3*((b+1)*(b+1)*(b+1)*(b+1)-b*b*b*b)-3*((b+2)*(b+2)*(b+2)*(b+2)-2*((b+1)*(b+1)*(b+1)*(b+1)-b*b*b*b)-b*b*b*b)<<endl;
    if(a==4) cout<<24<<endl;
    if(a>4)cout<<0<<endl;
}
//数学的解法(汚い)
//暗証番号は10000通りしかないから一つ一つの暗証番号を条件満たしてるか確認すればいい感じの解放になる。
