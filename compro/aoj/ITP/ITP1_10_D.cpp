#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

void ndist(double n,vector <double> x,vector <double> y){
    double temp=0;
    for(size_t i=0;i<x.size();i++){
        temp+=pow(fabs(x[i]-y[i]),n);
    }
    cout<<fixed<<setprecision(6);
    cout<<pow(temp,1/n)<<endl;
}

int main(){
    double n;
    cin>>n;
    vector <double> x(n);
    vector <double> y(n);
    for(size_t i=0;i<n;i++){
        cin>>x[i];
    }
    for(size_t i=0;i<n;i++){
        cin>>y[i];
    }
    ndist(1,x,y);
    ndist(2,x,y);
    ndist(3,x,y);
    double max=0;
    for (int i=0;i<n;i++){
        if(fabs(x[i]-y[i])>max) max=fabs(x[i]-y[i]);
    }
    cout<<max<<endl;

}
/* 
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<double> x(n);
    for(int i=0; i<n; i++){
        cin >> x[i];
    }
    for(int i=0; i<n; i++){
        double y;
        cin >> y;
        x[i] = abs(x[i] -y);
    }

    double s1=0, s2=0, s3=0, sinf=0;
    for(int i=0; i<n; i++){
        s1 += x[i];
        s2 += x[i]*x[i];
        s3 += x[i]*x[i]*x[i];
        sinf = max(sinf, x[i]);
    }
    s2 = sqrt(s2);
    s3 = cbrt(s3);
    cout << fixed << setprecision(10);
    cout << s1 << endl << s2 << endl << s3 << endl << sinf << endl;
    return 0;
}
 */
//一般化って感じではないけどこの問題に対しての最適コードって感じ。LIKE
// sinf = max(sinf, x[i]);のところはめっちゃ使える。forループの中でif噛ませずに最大値取るときは絶対にこれでやる。
