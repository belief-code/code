#include<iostream>
using namespace std;

int dp[100000];

int fib(int n){
    dp[0]=0;
    dp[1]=1;

    for(int i=2;i<=n;i++) dp[i]=dp[i-1]+dp[i-2];

    return dp[n];
}

int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cout<<i<<" "<<fib(i)<<endl;
    }
    return 0;
}