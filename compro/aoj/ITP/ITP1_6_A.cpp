#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << a[n - 1];
    for(int j = 1; j < n; j++) {
        cout << ' ' << a[n - j - 1];
    }
    cout << endl;
    return 0;
}