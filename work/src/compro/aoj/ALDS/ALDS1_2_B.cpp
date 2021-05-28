#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int> v){
    int count=0;
    for(int i=0;i<v.size()-1;i++){
        int minj=i;
        for(int j=i+1;j<v.size();j++){
            if(v[j]<v[minj]) minj=j;
        }
        if(i!=minj) count++;
        swap(v[i],v[minj]);
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<(i==v.size()-1?"\n":" ");
    }
    cout<<count<<endl;
}
int main(){
    int n,k;cin>>n;
    vector <int> a;
    for(int i=0;i<n;i++){
        cin>>k;
        a.push_back(k);
    }
    selectionSort(a);

    return 0;    
}