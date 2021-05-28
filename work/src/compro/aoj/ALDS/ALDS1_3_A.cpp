#include<iostream>
using namespace std;
typedef long long ll;

struct Stack{
    ll table[1000];
    ll size;

    Stack(){
        size=0;
        //cout<<"ok"<<endl;
    }
    bool empty(){
        return size==0;
    }
    void push(ll x){
        table[size]=x;
        size++;
    }
    ll pop(){
        if(empty())return 0;
        size--;
        return table[size];
    }
};

ll calc(ll x,string op,ll y){
    if(op=="+") return x+y;
    if(op=="-") return x-y;
    if(op=="*") return x*y;
    else{
        cout<<"error"<<endl;
        return 0;
    }
}

int main(){
    string str;
    ll numA,numB;
    Stack stack;

    while(cin>>str){
        if(str=="+"||str=="-"||str=="*"){
            numA=stack.pop();
            numB=stack.pop();
            stack.push(calc(numB,str,numA));
        }else{
            numA=0;
            for(int i=0;i<(int)str.size();i++){
                numA*=10;
                numA+=str[i]-'0';
            }
            stack.push(numA);
        }
    }
    cout<<stack.pop()<<endl;
    return 0;
}

