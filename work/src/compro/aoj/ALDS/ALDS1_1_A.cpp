#include<iostream>
#include<vector>
using namespace std;

void coutVector(vector <int> v){
    cout<<v[0];
    for(int i=1;i<v.size();i++){
        cout<<' '<<v[i];
    }
    cout<<endl;
}

void insertionSort(vector <int> v){
    for(size_t i=1;i<v.size();i++){
        int temp=v[i];
        int j=i-1;
        while(j>=0&&v[j]>temp){
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=temp;

        coutVector(v);
    }

}

int main(){
    int n;
    cin>>n;
    vector <int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    coutVector(v);
    insertionSort(v);

    return 0;
}