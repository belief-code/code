#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;cin>>n;
    string s;cin>>s;
    int ans=0;
    for(int i=0;i<=999;i++){
        string i1=to_string(i/100),i2=to_string((i/10)%10),i3=to_string(i%10);
        ll test=s.find(i1);
        if(s.find(i1)!=string::npos&&s.find(i2,s.find(i1)+1)!=string::npos&&s.find(i3,s.find(i2,s.find(i1)+1)+1)!=string::npos){
            ans++;
        }
    }

    cout<<ans<<endl;
    return 0;
}

//値域で全探索
//findで検索して解いたけど3回もfindするなら自分でループ回して探したほうがキレイだったかも