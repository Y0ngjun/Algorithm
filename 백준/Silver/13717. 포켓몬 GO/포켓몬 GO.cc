#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int ans_int = 0;
    int count = 0;
    string ans_name;

    for (int i = 0; i < N; i++)
    {
        string name;
        cin >> name;

        int K, M;
        cin >> K >> M;

        int E = (M - 2) / (K - 2);
        ans_int += E;

        if (E > count)
        {
            count = E;
            ans_name = name;
        }
    }

    cout << ans_int << '\n';
    cout << ans_name;

    return 0;
}
