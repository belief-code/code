#include<iostream>
#include<string>
using namespace std;


int main(){
    string s,ord,p;
    int q,a,b;
    cin>>s>>q;
    for(int i=0;i<q;i++){
        cin>>ord;
        if(ord=="print"){
            cin>>a>>b;
            for(int i=a;i<=b;i++){
                cout<<s[i];
            }
            cout<<endl;
        }else if(ord=="reverse"){
            cin>>a>>b;
            p=s.substr(a,b-a+1);
            for(int i=a;i<=b;i++){
                s[i]=p[b-i];
            }
        }else if(ord=="replace"){
            cin>>a>>b>>p;
            s=s.replace(a,b-a+1,p);
        }
    }
}

/* 
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	string s;
	int q;
	
	cin >> s;
	cin >> q;
	
	for(int i=0; i<q; ++i){
		string od, p;
		int a, b;
		
		cin >> od >> a >> b;
		if(od=="replace"){
			cin >> p;
			s = s.replace(a, b-a+1, p);
		}
		else if(od=="print"){
			cout << s.substr(a, b-a+1) << endl;
		}
		else if(od=="reverse"){
			string tmp = s.substr(a, b-a+1);
			reverse(tmp.begin(), tmp.end());
			//cout <<"tmp=" << tmp <<endl;
			s = s.replace(a, b-a+1, tmp);	
		}
		
		//cout << s << endl;
		
	}
	return 0;
}
 */
//めっちゃキレイ。substrは使い方が色々出来てめっちゃ便利。この問題はreverse知ってると有利っぽい。
//基本的に文字列の変換などするときはsubstrとreplaceの使用をよく考えたほうが良い。