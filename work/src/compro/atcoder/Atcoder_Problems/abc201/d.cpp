#include<iostream>
#include<vector>
using namespace std;

int main(){
    int h,w;cin>>h>>w;
    vector<vector<char>> a(h,vector<char>(w));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>a[i][j];
    }

/*     for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout<<a[i][j]<<(w-j-1?" ":"\n");
        }
    } */
    vector<vector<int>> dp(h,vector<int>(w));\
    //外枠だけ最初に埋める
    dp[h-1][w-1]=0;
    for(int i=0;i<h;i++){

    }

    for(int i=1;i<h;i++){
        for(int j=1;j<w;j++){
            if(i==0&&j==0) break;
            dp[h-1-i][w-1-j]=dp[h-i][w-j];
        }
    }
}


//解法はわかったけど実装があまりにもだるい。未来の自分に託す
//i+jの偶奇で場合分けして右の値と左の値を比較して右下から埋めていく。
//一番右の列と一番下の列は最初に全部埋めておかないと場合分けがだるい
//メモ取って再帰関数で回せば場合分け要らないんだけど宣言書き直すのだるいからやめたけど、場合分けのほうが多分だるい。
