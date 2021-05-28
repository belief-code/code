#include<iostream>
#include<vector>
#include<tuple>
using namespace std;



tuple <int,vector<int>> insertionSort(vector<int> v,int h,int cnt){
    int t,j;
    for(int i=h;i<v.size();i++){
        t=v[i];
        j=i-h;
        while(j>=0&&v[j]>t){
            v[j+h]=v[j];
            j=j-h;
            cnt++;
        }
        v[j+h]=t;
    }
    return forward_as_tuple(cnt,v);    
}
void shellSort(vector<int> v){
    int cnt=0;
    vector<int> h;
    h.push_back(1);
    for(int i=1;i<v.size();i++){
        if((3*h[i-1]+1)>v.size()) break;//だめっぽかったらこの行のi->i-1にする。
        h.push_back(3*h[i-1]+1);
    }
    /* for(int i=0;i<h.size();i++){
        cout<<h[i]<<(i==h.size()-1?"\n":" ");
    } */
    for(int i=h.size()-1;i>=0;i--){
        //cout<<i<<h[i]<<endl;
        tie(cnt,v)=insertionSort(v,h[i],cnt);
    }
    cout<<h.size()<<endl;
    for(int i=h.size()-1;i>=0;i--){
        cout<<h[i]<<(i==0?"\n":" ");
    }
    cout<<cnt<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
}
int main(){
    int n,k;cin>>n;
    vector <int> v;
    for(int i=0;i<n;i++){
        cin>>k;
        v.push_back(k);
    }
    shellSort(v);
}


/* 
#include<bits/stdc++.h>
using namespace std;
int cnt;
void insertionSort(int *A,int n,int g){
  for(int i=g;i<n;i++){
    int v=A[i];
    int j=i-g;
    while(j>=0&&A[j]>v){
      A[j+g]=A[j];
      j-=g;
      cnt++;
    }
    A[j+g]=v;
  }
}
void shellSort(int *A,int n){
  cnt=0;
  int r=1;
  vector<int> G;
  while(r<=n){
    G.push_back(r);
    r*=2;
  }
  int m=G.size();
  reverse(G.begin(),G.end());
  cout<<m<<endl;
  for(int i=0;i<m;i++) cout<<G[i]<<" \n"[i==m-1];
  for(int i=0;i<m;i++) insertionSort(A,n,G[i]);
  cout<<cnt<<endl;
}
signed main(){
  int n;
  cin>>n;
  int A[n];
  for(int i=0;i<n;i++) cin>>A[i];
  shellSort(A,n);
  for(int k=0;k<n;k++) cout<<A[k]<<endl;
  return 0;
}
 */
//自分も考えたけどグローバル変数にcntを置くことで戻り値のごちゃごちゃを回避してる。
//あとポインタを渡すことで書き換えを関数内でやっても全体に作用するようにしてる。
//参照渡しっていうのがvectorにはあってこれを使うと値を関数内で変更出来るっぽい。
// Type sumVector(vector<Type>& v)こういう感じ。多分こうやって渡さないと複製作ってそれ弄ることになる
//複製を作る時間分のロスもあるから基本的には参照渡しでいいのかも。値を変えたくなければconstつければいいし