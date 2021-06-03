#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    int n;cin>>n;
    ll inf=100000000000;
    ll tempx,tempy;
    vector<ll> minx(2,inf);
    vector<ll> miny(2,inf);
    vector<ll> maxx(2,-inf);
    vector<ll> maxy(2,-inf);
    for(int i=0;i<n;i++){
        cin>>tempx>>tempy;
        minx.push_back(tempx);
        miny.push_back(tempy);
        maxx.push_back(tempx);
        maxy.push_back(tempy);
        sort(minx.begin(),minx.end());
        sort(miny.begin(),miny.end());
        sort(maxx.begin(),maxx.end());
        sort(maxy.begin(),maxy.end());
        reverse(maxx.begin(),maxx.end());
        reverse(maxy.begin(),maxy.end());
        minx.erase(minx.end()-1);
        miny.erase(miny.end()-1);
        maxx.erase(maxx.end()-1);
        maxy.erase(maxy.end()-1);
    }
    vector<ll> ans(6);
    ans[0]=maxx[0]-minx[0];
    ans[1]=maxx[0]-minx[1];
    ans[2]=maxx[1]-minx[0];
    ans[3]=maxy[0]-miny[0];
    ans[4]=maxy[0]-miny[1];
    ans[5]=maxy[1]-miny[0];
    sort(ans.begin(),ans.end());
    cout<<ans[4]<<endl;

    return 0;
}