#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    int h,w,x,y,ans=0;cin>>h>>w>>x>>y;
    w--;
    y--;
    vector<string> s(h+1);
    for(int i=1;i<=h;i++){
        cin>>s[i];
    }
    for(int i=1;i<=x-1;i++){
        if(s[x-i][y]=='.')ans++;
        else break;
    }
    for(int i=1;i<=h-x;i++){
        if(s[x+i][y]=='.') ans++;
        else break;
    }
    for(int i=1;i<=y;i++){
        if(s[x][y-i]=='.') ans++;
        else break;
    }
    for(int i=1;i<=w-y;i++){
        if(s[x][y+i]=='.') ans++;
        else break;
    }
    if(s[x][y]=='#') ans=0;
    else ans++;

    cout<<ans<<endl;

    return 0;
}
//升目系の問題は添字の最初を0じゃなくて1にしたほうがわかりやすい