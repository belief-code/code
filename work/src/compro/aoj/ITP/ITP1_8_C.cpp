#include<iostream>
#include<string>
using namespace std;

int main(){
    int counter[26]={};
    string s;
    while(getline(cin,s)){
        for(int i=0;i<(int)s.size();i++){
            if(isupper(s[i])) s[i]=tolower(s[i]);
            if(isalpha(s[i])) counter[s[i]-'a']++;
        }
    }
    for(int i=0;i<26;i++){
        cout<<(char)('a'+i)<<" : "<<counter[i]<<endl;
    }
    return 0;
}