#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector <int> v){
    int flag=1;
    int count=0;
    while(flag){
        flag=0;
        for(int i=0;i<v.size()-1;i++){
            if(v[i]>v[i+1]){
                swap(v[i],v[i+1]);
                flag=1;
                count++;
            }
        }
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<(i==v.size()-1?'\n':' ');
    }
    cout<<count<<endl;
}
int main(){
    int n,k;cin>>n;
    vector <int> v;
    for(int i=0;i<n;i++){
        cin>>k;
        v.push_back(k);
    }

    bubbleSort(v);
}

//バブルソートのソート上からやる風潮謎。