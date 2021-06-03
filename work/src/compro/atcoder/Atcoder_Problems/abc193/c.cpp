#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int,int>;

int main(){
    ll n;cin>>n;
    ll ans=0;
    vector<bool> box(sqrt(n)+2,0);
    ll i=2;//ここのiもintでそれでも多分バグってた
    while(i<=sqrt(n)){
        if(box[i]==1){
            i++;
            continue;
        }else{
            for(ll j=i*i;j<=sqrt(n);j*=i) box[j]=1;//ここのjをintにしたせいでバグった
        }
        ll temp=log(n)/log(i);
        ans+=temp-1;
        i++;
        }
    cout<<n-ans<<endl;
    return 0;
}

//くっそバグった(segment error)ギリギリ型に入るか入らないかくらいのやつはまじでやめたほうが良い。
//あと一回操作を行ったら型範囲を超えるけど流石にもう一回操作しないだろ→する
//みたいなことがあるから基本的にllで定義しといたほうが良い。

//理論面で行くと上のは数学的解法でなんともいえない。
//これ重複の回避のために生成される値の被りを回避するのは普通に実装すると大変だから
//生成元を絞ったんだけど生成された値の被りを回避することが簡単なset構造なるものがあるらしく
//それで実装するとめっちゃ簡単だった。知らなかったので仕方ない。