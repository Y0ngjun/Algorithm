// BOJ 2666 벽장문의 이동
#include <iostream>
#include <vector>

using namespace std;

// 최솟값 업데이트
void update(int& a, int b)
{
    if (b == -1)
    {
        return;
    }

    if (a == -1)
    {
        a = b;
    }
    else
    {
        a = min(a, b);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 0-based
    int n, a, b, m;
    cin >> n >> a >> b >> m;
    --a;
    --b;

    vector<int> arr(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> arr[i];
        --arr[i];
    }

    // dp[i][j] = arr[i]번째 벽장까지 사용하고, j번째 벽장이 열려 있을 때 벽장문의 최소 이동 횟수
    vector<vector<int>> dp(m, vector<int>(n, -1));
    dp[0][a] = abs(arr[0] - b);
    dp[0][b] = abs(arr[0] - a);

    for (int i = 0; i < m - 1; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (dp[i][j] != -1)
            {
                update(dp[i + 1][j], dp[i][j] + abs(arr[i + 1] - arr[i]));
                update(dp[i + 1][arr[i]], dp[i][j] + abs(arr[i + 1] - j));
            }
        }
    }

    int ans = -1;
    for (int i = 0; i < n; ++i)
    {
        update(ans, dp[m - 1][i]);
    }

    cout << ans;

    return 0;
}
