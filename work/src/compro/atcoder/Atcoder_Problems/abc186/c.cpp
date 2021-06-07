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
    int n,ans=0;cin>>n;
    repn(i,n){
        int tmp10=i,tmp8=i;
        rep(j,10){
            if(tmp10%10==7){
                break;
            }
            if(tmp8%8==7){
                break;
            }
            tmp10/=10;
            tmp8/=8;
            if(j==9) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
//10^5=8^xをググってもすぐに出てこなくてだるかった。多い分にはどうでもいいから多めにしてAC
//関数電卓をインストールしておくべきと思った。