#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int,int>;

int main(){
    vector<int> v(3);
    v[0]=0;
    v[1]=1;
    v[2]=2;
    cout<<v.end()-v.begin()<<v[v.end()-v.begin()]<<endl;

    return 0;
}