#include<iostream>
#include<string>
using namespace std;

int main(){
    int n,ans1,ans2;
    string s1,s2;
    ans1=0;
    ans2=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s1>>s2;
        if(s1>s2) ans1+=3;
        if(s1==s2){
            ans1++;
            ans2++;
        }
        if(s1<s2) ans2+=3;
    }
    cout<<ans1<<' '<<ans2<<endl;
    return 0;
}

/* 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a=0, b=0;
    for(int i=0; i<n; i++){
        string s,t;
        cin >> s >> t;
        if(s==t){
            a++;
            b++;
        }else if(s > t){
            a += 3;
        }else{
            b += 3;
        }
    }
    cout << a << " " << b << endl;
    return 0;
}
 */
//int a=0,b=0という表記法がある。便利。ちなみにこれalgorithm要らない。