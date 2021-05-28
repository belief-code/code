#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool judge(int t,int x,int y){
    t=abs(t);x=abs(x);y=abs(y);
    if(t<x+y) return 0;
    else if((t-x-y)%2==0) return 1;
    else return 0;
}

int main(){
    int n;cin>>n;
    bool ans=0;
    vector <bool> dp(n+1);
    vector <vector<int>> txy(n+1,vector<int>(3));
    txy[0][0]=0;txy[0][1]=0;txy[0][2]=0;

    for(int i=1;i<=n;i++){
        cin>>txy[i][0]>>txy[i][1]>>txy[i][2];
    }
    //for(int i=0;i<n;i++) cout<<txy[i][0]<<endl;

    dp[0]=1;
    int count=1;
    while(dp[count-1]){
        if(judge(txy[count][0]-txy[count-1][0],txy[count][1]-txy[count-1][1],txy[count][2]-txy[count-1][2])){
            dp[count]=1;
        }else{
            dp[count]=0;
        }
        count++;
        if(dp[n]==1){
            ans=1;
            break;
        }
    }


    if(ans) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }

    return 0;
}