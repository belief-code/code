#include <iostream>
using namespace std;

int main() {
    int num[5][4][11] = {};
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int b, f, r, v;
        cin >> b >> f >> r >> v;
        num[b][f][r] += v;
    }
    for(int j = 1; j < 5; j++) {
        for(int k = 1; k < 4; k++) {
            for(int l = 1; l < 11; l++) {
                cout << ' ' << num[j][k][l];
                if(l == 10)
                    cout << endl;
                if(j == 4 && k == 3 && l == 10)
                    break;
                if(k == 3 && l == 10)
                    cout << "####################" << endl;
            }
        }
    }
}