#include <iostream>
#include <string>
using namespace std;
struct Dice {
    int s[6];
    void roll(char c) {
        int b;
        if(c == 'E') {
            b = s[0];
            s[0] = s[3];
            s[3] = s[5];
            s[5] = s[2];
            s[2] = b;
        }
        if(c == 'W') {
            b = s[0];
            s[0] = s[2];
            s[2] = s[5];
            s[5] = s[3];
            s[3] = b;
        }
        if(c == 'N') {
            b = s[0];
            s[0] = s[1];
            s[1] = s[5];
            s[5] = s[4];
            s[4] = b;
        }
        if(c == 'S') {
            b = s[0];
            s[0] = s[4];
            s[4] = s[5];
            s[5] = s[1];
            s[1] = b;
        }
        if(c == 'R') {
            b = s[1];
            s[1] = s[2];
            s[2] = s[4];
            s[4] = s[3];
            s[3] = b;
        }
    }

    bool judge(Dice d2){
        for(int i=0;i<6;i++){
            if(s[i]!=d2.s[i]) return false;
        }
        return true;
    }
    int top() { return s[0]; }
    int right() { return s[2]; }
    int left() { return s[3]; }
    int front() { return s[1]; }
    int back() { return s[4]; }
    int bottom() { return s[5]; }

};

int main(){
    Dice d1,d2;
    int flag=0;
    for(int i=0;i<6;i++) cin>>d1.s[i];
    for(int i=0;i<6;i++) cin>>d2.s[i];

    for(int i=0;i<4;i++){
        d1.roll('R');
        flag+=d1.judge(d2);
    }
    d1.roll('N');
    for(int i=0;i<4;i++){
        d1.roll('E');
        flag+=d1.judge(d2);
    }
    d1.roll('N');
    for(int i=0;i<4;i++){
        d1.roll('R');
        flag+=d1.judge(d2);
    }
    d1.roll('N');
    for(int i=0;i<4;i++){
        d1.roll('E');
        flag+=d1.judge(d2);
    }
    d1.roll('R');
    for(int i=0;i<4;i++){
        d1.roll('N');
        flag+=d1.judge(d2);
    }
    d1.roll('R');
    d1.roll('R');
    for(int i=0;i<4;i++){
        d1.roll('N');
        flag+=d1.judge(d2);
    }
    if(flag>0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
    return 0;


}