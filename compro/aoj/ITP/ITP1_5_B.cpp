#include <iostream>
using namespace std;

int main()
{
    int H, W;
    while (cin >> H >> W)
    {
        if (H == 0)
            break;
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if (i == 0 || j == 0 || i == H - 1 || j == W - 1)
                    cout << '#';
                else
                    cout << '.';
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}