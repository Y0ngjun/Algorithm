// BOJ 19639 배틀로얄
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int X, Y, M;
    cin >> X >> Y >> M;

    vector<int> x(X);
    for (int i = 0; i < X; i++)
        cin >> x[i];

    vector<int> y(Y);
    for (int i = 0; i < Y; i++)
        cin >> y[i];

    int i = 0, j = 0, m = M, half = M / 2;
    vector<int> ans;

    while (i < X || j < Y)
    {
        if (m > half)
        {
            if (i < X)
            {
                m -= x[i++];
                ans.push_back(-i);
            }
            else
            {
                m = min(M, m + y[j++]);
                ans.push_back(j);
            }
        }
        else
        {
            if (j < Y)
            {
                m += y[j++];
                ans.push_back(j);
            }
            else
            {
                m = max(0, m - x[i++]);
                ans.push_back(-i);
            }
        }

        if (m <= 0)
        {
            ans = { 0 };
            break;
        }
    }

    for (int i : ans)
        cout << i << '\n';

    return 0;
}
