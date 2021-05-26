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

    bool judge(Dice d2) {
        for(int i = 0; i < 6; i++) {
            if(s[i] != d2.s[i])
                return false;
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
    int n;
    cin>>n;
    Dice d[n];
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<6;j++){
            cin>>d[i].s[j];
        }
    }
    for(int c=0;c<n-1;c++){
        for(int e=c+1;e<n;e++){

        for(int i=0;i<4;i++){
            d[c].roll('R');
            if(d[c].judge(d[e]))
                ans = 1;
        }
        d[c].roll('N');
        for(int i=0;i<4;i++){
            d[c].roll('E');
            if(d[c].judge(d[e]))
                ans = 1;
        }
        d[c].roll('N');
        for(int i=0;i<4;i++){
            d[c].roll('R');
            if(d[c].judge(d[e]))
                ans = 1;
        }
        d[c].roll('N');
        for(int i=0;i<4;i++){
            d[c].roll('E');
            if(d[c].judge(d[e]))
                ans = 1;
        }
        d[c].roll('R');
        for(int i=0;i<4;i++){
            d[c].roll('N');
            if(d[c].judge(d[e]))
                ans = 1;
        }
        d[c].roll('R');
        d[c].roll('R');
        for(int i=0;i<4;i++){
            d[c].roll('N');
            if(d[c].judge(d[e]))
                ans = 1;
        }
    }
    }
    cout<<(ans?"No":"Yes")<<endl;
    
    return 0;


}