#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<string> answer;

void recursive(string s, int n0, int n1, int m, const vector<int>& nums)
{
	if (m == 0)
		answer.push_back(s);
	else
	{
		for (int i = n0; i <= n1; ++i)
		{
			string s0 = s + to_string(nums[i]) + " ";
			recursive(s0, i, n1, m - 1, nums);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> nums(n);
	for (int i = 0; i < n; ++i)
		cin >> nums[i];

	sort(nums.begin(), nums.end());

	recursive("", 0, n - 1, m, nums);

	unordered_set<string> printed;
	for (string s : answer)
	{
		if (printed.count(s))
			continue;
		cout << s << '\n';
		printed.insert(s);
	}

	return 0;
}