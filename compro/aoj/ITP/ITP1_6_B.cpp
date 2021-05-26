#include <iostream>
using namespace std;

int main() {
    int n, b;
    char a;
    int card[4][13] = {};
    cin >> n;
    while(cin >> a >> b) {
        if(a == 'S')
            card[0][b - 1] = 1;
        if(a == 'H')
            card[1][b - 1] = 1;
        if(a == 'C')
            card[2][b - 1] = 1;
        if(a == 'D')
            card[3][b - 1] = 1;
    }
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 13; j++) {
            if(card[i][j] == 0) {
                if(i == 0)
                    cout << 'S' << ' ' << j + 1 << endl;
                if(i == 1)
                    cout << 'H' << ' ' << j + 1 << endl;
                if(i == 2)
                    cout << 'C' << ' ' << j + 1 << endl;
                if(i == 3)
                    cout << 'D' << ' ' << j + 1 << endl;
            }
        }
    }
    return 0;
}