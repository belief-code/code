#include<iostream>
#include<string>
using namespace std;

int main(){
    string w,s;
    int c=0;
    cin>>w;
    while(cin>>s){
        for(int i=0;i<s.size();i++){
            if(isupper(s[i])) s[i]=tolower(s[i]);
        }
        if(w==s) c++;
    }
    cout<<c<<endl;
}
/* #include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	string str;
	cin >> str;
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	
	int count=0;
	while(1){
		string tmp;
		cin >> tmp;
		if(tmp=="END_OF_TEXT") break;
		transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
		if(str==tmp) count++;
	}
	cout << count << endl;
	return 0;
} */
//algorithmのtransformを使うと文字列全体に色々できる。