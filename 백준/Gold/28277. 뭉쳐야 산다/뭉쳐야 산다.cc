#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<set<int>> S(N + 1);

    for (int i = 1; i <= N; i++)
    {
        int n;
        cin >> n;

        for (int j = 1; j <= n; j++)
        {
            int s;
            cin >> s;

            S[i].insert(s);
        }
    }

    for (int i = 1; i <= Q; i++)
    {
        int c;
        cin >> c;

        if (c == 1)
        {
            int a, b;
            cin >> a >> b;

            if (S[b].size() > S[a].size())
            {
                S[a].swap(S[b]);
            }

            S[a].merge(S[b]);
            S[b].clear();
        }
        else if (c == 2)
        {
            int a;
            cin >> a;

            cout << S[a].size() << '\n';
        }
    }

    return 0;
}
