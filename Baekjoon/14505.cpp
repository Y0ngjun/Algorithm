// BOJ 14505 팰린드롬 개수 구하기 (Small)
#include <iostream>
#include <vector>

using namespace std;

int palindromeCount(string s, int start, int end, vector<vector<int>>& dp)
{
    if (start > end)
    {
        return 0;
    }

    if (dp[start][end] != -1)
    {
        return dp[start][end];
    }

    int temp = palindromeCount(s, start, end - 1, dp);

    for (int i = start; i <= end; ++i)
    {
        if (s[i] == s[end])
        {
            temp += palindromeCount(s, i + 1, end - 1, dp) + 1;
        }
    }

    return dp[start][end] = temp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout << palindromeCount(s, 0, n - 1, dp);

    return 0;
}
