#include<iostream>
using namespace std;

int main(){
    while(1){
        int H,W;
        cin>>H>>W;
        if(H==0) break;
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if((i+j)%2==0) cout<<'#';
                else cout<<'.';
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}