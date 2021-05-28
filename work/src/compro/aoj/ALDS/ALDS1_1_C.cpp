#include<iostream>
#include<cmath>
using namespace std;

bool isprime(int n){
    int i=3;
    if(n==1) return false;
    if(n==2) return true;
    if(n%2==0) return false;
    while(i<=sqrt(n)){
        if(n%i==0) return false;
        i+=2;
    }
    return true;
}
int main(){
    int n;cin>>n;
    int num,count=0;

    for(int i=0;i<n;i++){
        cin>>num;
        if(isprime(num)) count++;
    }
    cout<<count<<endl;
}
/* 
#include <iostream>
using namespace std;
int main() {
    int ans = 0;
    int n, d;
    cin >> n;
    int i, j, k;
    for(i = 0; i < n; i++) {
        cin >> d;
        k = 1;
        for(j = 2; j * j <= d; j++) {
            if(d % j == 0) {
                k = 0;
                break;
            }
        }
        ans += k;
    }
    cout << ans << endl;
    return 0;
}
 */
//cmathを使わなくてもまあまあ工夫すれば行ける。2で割って時間を半分にしてもそんなに有意な差はない。