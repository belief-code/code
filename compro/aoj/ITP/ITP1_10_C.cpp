#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;

int main(){
    while(1){
    int n;
    double m,a,temp=0;
    cin>>n;
    if(n==0) break;
    vector <int> s(n);
    for(size_t i=0;i<s.size();i++){
        cin>>s[i];
    }
    m=(double)accumulate(s.begin(),s.end(),0)/s.size();
    //cout<<m;
    for(size_t i=0;i<s.size();i++){
        temp+=pow(s[i]-m,2)/n;
    } 
    a=sqrt(temp);
    cout<<fixed<<setprecision(6)<<a<<endl;
    }
}

//accumulate関数も結局内部でやってるのは足し算に過ぎないので除算するときなどは型に注意。
/* 
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    while(1){
        int n;
        cin >> n;
        if(n == 0) break;

        vector<double> x(n);
        double mean = 0;
        for(int i=0; i<n; i++){
            cin >> x[i];
            mean += x[i];
        }
        mean /= n;
        double v = 0;
        for(int i=0; i<n; i++){
            v += (x[i] -mean) *(x[i] -mean);
        }
        v /= n;
        cout << fixed << setprecision(10);
        cout << sqrt(v) << endl;
    }
    return 0;
}
 */
//sqrtもcoutの引数にできるのでこうしたほうがキレイ。