#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){

    //input
    int h,w;cin>>h>>w;
    vector<string> s(h);
    for(int i=0;i<h;i++){
        cin>>s[i];
    }


    //calc
    vector<string> cross(h+w-1,"");

    for(int k=0;k<h+w-1;k++){
        if(k<h){
            for(int l=0;l<min(l+1,w);l++){
                cross[k].push_back(s[k-l][l]);
            }
        }else{
            for(int l=0;l<min()){

            }
        }
    }
//斜めに要素取っていってそれで配列作ってそれに対して操作する。その操作の中で
//dp必要になるかも、組み合わせになるから。

}
//実装法が汚すぎる。場合分けは絶対に無くす気持ちでコード書く。