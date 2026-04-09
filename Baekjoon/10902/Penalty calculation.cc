// BOJ 10902
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int max_s = 0;
    int P = 0;

    for (int f = 1; f <= n; f++)
    {
        int t, s;
        cin >> t >> s;

        if (s > max_s)
        {
            max_s = s;
            P = t + (f - 1) * 20;
        }
    }

    cout << P;

    return 0;
}
