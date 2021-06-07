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
    int n;cin>>n;
    string temp;
    vector<string> notex;
    vector<string> ex;
    bool flag=0;
    rep(i,n){
        cin>>temp;
        if(temp[0]=='!')ex.pb(temp);
        else notex.pb(temp);
    }
    SORT(ex);
    rep(i,notex.size()){
        if(binary_search(ex.begin(),ex.end(),"!"+notex[i])){
            flag=1;
            cout<<notex[i]<<endl;
            break;
        }
    }
    if(flag==0) cout<<"satisfiable"<<endl;
    return 0;
}
//普通に全探索すると最大で10^5*10^5回一致するかどうかを判定する必要が出る。
//ソートしておけばLogNで探索できそうだから10^5*log10^5これなら一応行けそう。
//ソートされた文字列の配列を二分探索するのが少し難しそう。
//→二分探索出来るSTL binary_searchでAC。
//これ解説だとunorderd_setとか使ってるけど多分最悪計算量の場合TLEすると思う。ほぼ無いけど。
//とんでもない量のメモリ使えば高速にできそうだけどそれ以外だと最悪計算量O(nlogn)までしか行けない気がする。
