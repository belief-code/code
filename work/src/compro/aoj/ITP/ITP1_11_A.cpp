#include<iostream>
#include<vector>
using namespace std;

int main(){
    char od;
    vector <int> dice(7);
    vector <int> cdice(7);
    for(int i=1;i<=6;i++){
        cin>>dice[i];
    }
    while(cin>>od){
        cdice=dice;
        if(od=='E'){
           dice[1]=cdice[4];
           dice[3]=cdice[1];
           dice[6]=cdice[3];
           dice[4]=cdice[6];
        }
        if(od=='N'){
            dice[1]=cdice[2];
            dice[2]=cdice[6];
            dice[6]=cdice[5];
            dice[5]=cdice[1];
        } 
        if(od=='S'){
            dice[1]=cdice[5];
            dice[2]=cdice[1];
            dice[6]=cdice[2];
            dice[5]=cdice[6];
        }
        if(od=='W'){
            dice[1]=cdice[3];
            dice[3]=cdice[6];
            dice[6]=cdice[4];
            dice[4]=cdice[1];
        }
    }
    cout<<dice[1]<<endl;
    return 0;
}
/* 
#include <iostream>
using namespace std;
int a[6];
string s;
void C(int i,int j,int k,int l){
  int t;t=a[i];a[i]=a[j];a[j]=a[k];a[k]=a[l];a[l]=t;
}
int main(){
  for(int i=0;i<6;i++)cin>>a[i];
  cin>>s;
  for(int i=0;i<s.size();i++){
    if(s[i]=='E')for(int j=0;j<3;j++)C(0,2,5,3);
    if(s[i]=='W')C(0,2,5,3);
    if(s[i]=='S')for(int j=0;j<3;j++)C(0,1,5,4);
    if(s[i]=='N')C(0,1,5,4);
  }
  cout<<a[0]<<endl;
}
 */
//実装力があればこれが書きたかったって感じのコード。きれいでいいね

/* 
#include<iostream>
#include<string>
using namespace std;
struct Dice{
  int s[6];
  void roll(char c){
    int b;
    if(c=='E'){
      b=s[0];
      s[0]=s[3];
      s[3]=s[5];
      s[5]=s[2];
      s[2]=b;
    }
    if(c=='W'){
      b=s[0];
      s[0]=s[2];
      s[2]=s[5];
      s[5]=s[3];
      s[3]=b;
    }
    if(c=='N'){
      b=s[0];
      s[0]=s[1];
      s[1]=s[5];
      s[5]=s[4];
      s[4]=b;
    }
    if(c=='S'){
      b=s[0];
      s[0]=s[4];
      s[4]=s[5];
      s[5]=s[1];
      s[1]=b;
    }
  }
  int top() {
    return s[0];
  }
};
int main(){
  Dice d;
  for(int i=0;i<6;i++) cin >> d.s[i];
  string s;cin >> s;
  for(int i=0;i<s.size();i++) d.roll(s[i]);
  cout << d.top() << endl;
  return 0;
}
 */
//やってることはほぼ同じ。命令をstringで受けてるかどうかくらい。でも構造体を作っていてそこが決定的に違う。
//ここらへんの問題を通して構造体についてもおおまかに知ったほうが良さそう。