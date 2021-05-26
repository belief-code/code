#include<iostream>
#include<string>
using namespace std;

int main(){
    while(1){
        string s;
        int m;
        cin>>s>>m;
        if(s=="-") break;
        int h;

        for(int i=0;i<m;i++) {
            cin>>h;
            s=s.substr(h,s.size()-h)+s.substr(0,h);
        }
        cout<<s<<endl;
    }
    return 0;
}
/* 
#include<iostream>
#include<string>
using namespace std;
int main(){
  string str;
  cin >> str;
  int i;
  int m,b;
  while(str!="-"){
    cin >> m;
    for(i=0;i<m;i++){
      cin >> b;
      str=str.substr(b,str.size()-b)+str.substr(0,b);
    }
    cout << str << endl;
    cin >> str;
  }
  
} 
*/
//whileの条件文がこっちのほうがきれい。while文の中で配列定義するのはなんか場合によってはよくなさそう。
