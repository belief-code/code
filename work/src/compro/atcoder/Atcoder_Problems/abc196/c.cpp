#include<iostream>
#include<algorithm>
#include<string>    
#include<cmath>
using namespace std;

int main(){
    long n,temp,temp1,ans;cin>>n;
    long digit=to_string(n).size();
    if(digit%2==1){
        temp=pow(10,digit/2)-1;
        ans=temp;
    }else{
        temp=n/pow(10,digit/2);
        temp1=n%(long)pow(10,digit/2);
        if(temp>temp1)ans=temp-1;
        else ans=temp;
    }

    cout<<ans<<endl;
}

//半分に割って総当りしても高々10^6しか計算量行かないから間に合う



















/* #include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int main(){
    long num1;cin>>num1;
    string n=to_string(num1);
    long ans=0;
    vector <long> num(6);
    num[0]=9;
    for(int i=1;i<6;i++){
        num[i]=num[i-1]*10+num[i-1];
    }
    if(n.size()%2==1){
        ans=num[n.size()/2-1];
    }else{
        string tempn=n.substr(0,n.size()/2);
        for(int i=0;i<tempn.size();i++){
            num1/=10;
        }
        ans+=num1-pow(10,tempn.size()-1);
        ans+=num[n.size()/2-1];
    }
    cout<<ans<<endl;

    return 0;
}
 */
//実装法がよくない