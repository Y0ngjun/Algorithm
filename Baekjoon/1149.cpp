#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int>> dp(n, vector<int>(3));
	for (int i = 0; i < n; ++i)
		cin >> dp[i][0] >> dp[i][1] >> dp[i][2];

	vector<vector<int>> answer(n, vector<int>(3));
	answer[0][0] = dp[0][0];
	answer[0][1] = dp[0][1];
	answer[0][2] = dp[0][2];
	for (int i = 1; i < n; ++i)
	{
		answer[i][0] = dp[i][0] + (answer[i - 1][1] > answer[i - 1][2] ? answer[i - 1][2] : answer[i - 1][1]);
		answer[i][1] = dp[i][1] + (answer[i - 1][0] > answer[i - 1][2] ? answer[i - 1][2] : answer[i - 1][0]);
		answer[i][2] = dp[i][2] + (answer[i - 1][1] > answer[i - 1][0] ? answer[i - 1][0] : answer[i - 1][1]);
	}

	cout << *min_element(answer[n - 1].begin(), answer[n - 1].end());

	return 0;
}