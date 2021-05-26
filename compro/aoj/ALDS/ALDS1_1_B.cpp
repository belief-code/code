#include<iostream>
using namespace std;

int main(){
    int x,y;cin>>x>>y;
    int c;

    if(x>y) c=1;
    else c=-1;

    while(x!=0&&y!=0){
        if(c==1){
            x%=y;
            c*=-1;
            if(x==0) cout<<y<<endl;
        }else if(c==-1){
            y%=x;
            c*=-1;
            if(y==0) cout<<x<<endl;
        }
    }
}


/* 
#include<iostream>
using namespace std;
int gcd(int x,int y){
  if(x<y) swap(x,y);
  int b;
  while(x%y!=0){
    b=x;
    x=y;
    y=b%y;
  }
  return y;
}
int main(){
  int x,y;
  cin >> x >> y;
  cout << gcd(x,y) <<endl;
  return 0;
}
 */
//かしこい。初期条件をswapで固定するところとか条件分けを毎回x>yとなるようにして消すとか参考になる