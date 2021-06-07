#include<iostream>
#include<vector>
using namespace std;

vector<int> a={1,14,32,51,51,51,243,419,750,910};

//indexが条件を満たすかどうか
bool isOK(int index,int key){
    if(a[index]>=key) return true;
    else return false;
}

int binary_search(int key){
    int ng=-1;
    int ok=(int)a.size();

    while(abs(ok-ng)>1){
        int mid=(ok+ng)/2;

        if(isOK(mid,key))ok=mid;
        else ng=mid;
    }
    return ok;
}
/* //汎用的な二分探索のテンプレ
int binary_search(int key){
    int left = -1;
    int right =(int)a.size();

    while(right-left>1){
        int mid=left+(right-left)/2;
        if(isOK(mid,key)) right=mid;
        else left=mid;
    }

    return right;
} */

int main(){
    cout<< binary_search(51) <<endl;
    cout<< binary_search(1) <<endl;
    cout<< binary_search(910) <<endl;

    cout<< binary_search(52) <<endl;
    cout<< binary_search(0) <<endl;
    cout<< binary_search(911) <<endl;
}