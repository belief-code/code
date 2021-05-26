#include<iostream>
#include<vector>
using namespace std;

bool isStable(vector <string> v1,vector <string> v2){
    for(int i=0;i<v1.size()-1;i++){
        for(int j=i+1;j<v1.size();j++){
            for(int a=0;a<v1.size()-1;a++){
                for(int b=a+1;b<v1.size();b++){
                    if(v1[i][1]==v1[j][1]&&v1[i]==v2[b]&&v1[j]==v2[a]) {
                        //cout<<i<<j<<a<<b<<endl;
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void BubbleSort(vector <string> rv){
    vector <string> v;
    v=rv;
    for(int i=0;i<v.size();i++){
        for(int j=v.size()-1;j>i;j--){
            if(v[j][1]<v[j-1][1]) swap(v[j],v[j-1]);
        }
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<(i==v.size()-1?"\n":" ");
    }
    if(isStable(v,rv)) cout<<"Stable"<<endl;
    else cout<<"Not stable"<<endl;
}
void SelectionSort(vector <string> rv){
    vector <string> v;
    v=rv;
    for(int i=0;i<v.size();i++){
        int minj=i;
        for(int j=i+1;j<v.size();j++){
            if(v[minj][1]>v[j][1]){
                minj=j;
            }
        }
        swap(v[i],v[minj]);
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<(i==v.size()-1?"\n":" ");
    }
    if(isStable(v,rv)) cout<<"Stable"<<endl;
    else cout<<"Not stable"<<endl;

}

int main(){
    int n;cin>>n;
    vector <string> v;
    string k;
    for(int i=0;i<n;i++){
        cin>>k;
        v.push_back(k);        
    }
    BubbleSort(v);
    SelectionSort(v);
    
    return 0;
}



/* 
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n;
  cin>>n;
  string A[n];
  for(int i=0;i<n;i++) cin>>A[i];
  string C[n];
  for(int i=0;i<n;i++) C[i]=A[i];
  int ans=0;
  for(int i=0;i<n;i++){
    for(int j=n-1;j>i;j--){
      if(C[j][1]<C[j-1][1]){
	swap(C[j],C[j-1]);
      }
    }
  }
  string x[10],y[10];
  for(int i=0;i<n;i++){
    x[A[i][1]-'0']+=A[i][0];
    y[C[i][1]-'0']+=C[i][0];
  }
  ans=1;
  for(int i=0;i<10;i++) ans&=x[i]==y[i]; 
  for(int i=0;i<n;i++) cout<<C[i]<<" \n"[i==n-1];
  cout<<(ans?"Stable":"Not stable")<<endl;
  
  for(int i=0;i<n;i++) C[i]=A[i];
  for(int i=0;i<n;i++){
    int minj=i;
    for(int j=i;j<n;j++){
      if(C[j][1]<C[minj][1]){
	minj=j;
      }
    }
    if(i!=minj) swap(C[i],C[minj]);
  }
  
  for(int i=0;i<10;i++) x[i]=y[i]="";
  for(int i=0;i<n;i++){
    x[A[i][1]-'0']+=A[i][0];
    y[C[i][1]-'0']+=C[i][0];
  }
  ans=1;
  for(int i=0;i<10;i++) ans&=x[i]==y[i]; 
  for(int i=0;i<n;i++) cout<<C[i]<<" \n"[i==n-1];
  cout<<(ans?"Stable":"Not stable")<<endl;
  
  return 0;
}
 */
//Stableかどうかの判定がキレイすぎる。このタイプは一般化してパターン化出来るタイプじゃないから
//日々工夫していくしかない。その後のans&=x[i]==y[i];は普段遣い出来ると思う。
//これの意味はans= ans&bool;をやってる感じで両方が1じゃないと1を返さないので一回でも0になったらだめ。
//つまりすべて1である。ってのをキレイにやるとき使える。できるだけ使っていって覚え込んだほうが良い。
//ビット演算子なのでBoolでなくても多分比較できる。