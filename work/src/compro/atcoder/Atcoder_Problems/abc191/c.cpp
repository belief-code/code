#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

int main(){
    int h,w,ans=0;cin>>h>>w;
    vector<vector<int>> s(h,vector<int>(w));
    rep(i,h){
        rep(j,w){
            char tmp;cin>>tmp;
            if(tmp=='.')s[i][j]=0;
            else s[i][j]=1;
        }
    }
    
    rep(i,h-1){
        rep(j,w-1){
            int count=0;
            if(s[i][j]==1)count++;
            if(s[i][j+1]==1)count++;
            if(s[i+1][j]==1)count++;
            if(s[i+1][j+1]==1)count++;
            if(count==1||count==3)ans++;
        }
    }

    cout<<ans<<endl;

    return 0;
}
//座標平面上の各点に対してそこが頂点かどうか判定して数え上げていけば良い。頂点となる
//条件は周りの4空間の内1つもしくは3つが黒であること。
//いいひらめきでした。