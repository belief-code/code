#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = INT_MAX;

    for(int i = 0; i < n; i++) {
        cin >> a[i];

        int count = 0;
        while(a[i] % 2 == 0) {
            count++;
            a[i] /= 2;
        }
        if(count < ans)
            ans = count;
    }

    cout << ans << endl;

    return 0;
}