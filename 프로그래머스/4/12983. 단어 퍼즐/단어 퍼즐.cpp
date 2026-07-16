#include <string>
#include <vector>

using namespace std;

bool isSuffix(const string& t, const string& str, int end)
{
    int len = str.length();
    int start = end - len;

    if (start < 0)
        return false;

    for (int i = 0; i < len; i++)
        if (str[i] != t[start + i])
            return false;

    return true;
}

int solution(vector<string> strs, string t)
{
    int n = t.length();

    vector<int> dp(n + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (const string& str : strs)
        {
            if (!isSuffix(t, str, i))
                continue;

            int prefix = i - str.length();

            if (dp[prefix] == -1)
                continue;

            if (dp[i] == -1 || dp[i] > dp[prefix] + 1)
                dp[i] = dp[prefix] + 1;
        }
    }

    return dp[n];
}
