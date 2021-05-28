#include<iostream>
#include<cctype>
#include<string>
using namespace std;

int main(){
    string str;
    getline(cin,str);
    for(int i=0;i<str.size();i++){
        char ch=str.at(i);
        if(islower(ch)) str.at(i)=(char)toupper(ch);
        if(isupper(ch)) str.at(i)=(char)tolower(ch);
    }
    cout<<str<<endl;
}
#include <iostream>
#include <vector>
using namespace std;

/* int main(){
    string s;
    getline(cin, s);

    for(int i=0; i<(int)s.length(); i++){
        if('A' <= s[i] && s[i] <= 'Z'){
            s[i] = 'a' +s[i]-'A';
        }else if('a' <= s[i] && s[i] <= 'z'){
            s[i] = 'A' +s[i]-'a';
        }
    }
    cout << s << endl;
    return 0;
} */
//nをaから数えた数とNをAから数えた数が同じだからこういう事ができる。
//string型は表示形式が違うだけで配列と同じような振る舞いをメモリ上でしていて多分内部もかなりメタな部分まで数字で表記されてる。
