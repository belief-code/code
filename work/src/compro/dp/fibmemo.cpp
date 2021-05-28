#include<iostream>
#include<climits>
using namespace std;

bool done[100000];
int memo[100000];

int fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;

    if(done[n]) return memo[n];

    done[n]=true;
    return memo[n]=fib(n-1)+fib(n-2);
}


int main(){
    for(int i=10;i<30;i++){
        cout<<i<<" "<<fib(i)<<endl;
    }
    
    return 0;
}