#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool Compare(const pair<string, int>& a, const pair<string, int>& b)
{
	if (a.second != b.second)
		return a.second > b.second;
	else if (a.first.size() != b.first.size())
		return a.first.size() > b.first.size();
	else
		return a.first < b.first;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	unordered_map<string, int> word;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		if (str.size() < m)
			continue;
		++word[str];
	}

	vector<pair<string, int>> ans(word.begin(), word.end());
	sort(ans.begin(), ans.end(), Compare);
	for (const auto& iter : ans)
		cout << iter.first << '\n';

	return 0;
}