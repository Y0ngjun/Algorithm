// BOJ 1954 화학실험
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> gas(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i] >> gas[i];
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; ++i)
    {
        int minGas = 0;

        for (int j = 1; j < n; ++j)
        {
            if (gas[j] < gas[minGas])
            {
                minGas = j;
            }
        }

        gas[minGas] += a[minGas];
    }

    for (int i = 1; i < n; ++i)
    {
        if (gas[i] != gas[0])
        {
            cout << 0;

            return 0;
        }
    }

    cout << gas[0];

    return 0;
}
