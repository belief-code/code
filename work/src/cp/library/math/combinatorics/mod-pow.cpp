/*
概要:ある値の冪乗を求める
使い方:mod_pow(x,n,p):x^n(modp)を返す.
計算量:O(logn)
*/

template<typename T>
T mod_pow(T x,int64_t n,const T &p){
    T ret=1;
    while(n>0){
        if(n&1)(ret*=x)%=p;
        (x*=x)%=p;
        n>>=1;
    }
    return ret%p;
}