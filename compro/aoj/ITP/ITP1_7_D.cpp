#include <iostream>
using namespace std;
#define rep(i, x) for(int i = 0; i < (x); i++)

int main() {
    int n, m, l;
    cin >> n >> m >> l;
    int mata[n][m] = {};
    int matb[m][l] = {};
    int matc[n][l] = {};

    rep(i, n) { rep(j, m) cin >> mata[i][j]; }
    rep(i, m) { rep(j, l) cin >> matb[i][j]; }

    rep(i, n) {
        rep(j, l) {
            long long sum = 0;
            rep(k, m) {
            sum += mata[i][k] * matb[k][j];
            }
            if(j==l-1){
                cout<<sum<<endl;
                break;
            }
            cout << sum << ' ';
        }
    }
}
