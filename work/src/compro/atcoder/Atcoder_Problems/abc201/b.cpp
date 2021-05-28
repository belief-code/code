#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct mypair{
    string x;
    int t;

    bool operator<(const mypair &other){
        if(t<other.t) return 1;
        else return 0;
    }
};

int main(){
    int n;cin>>n;
    vector <mypair> m(n);

    for(int i=0;i<n;i++){
        cin>>m[i].x>>m[i].t;
    }

    sort(m.begin(),m.end());
    reverse(m.begin(),m.end());
    
    cout<<m[1].x<<endl;

    return 0;
}