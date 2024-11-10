#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<string> answer;

void recursive(string s, int m, vector<int>& num, vector<bool>& erased)
{
	if (m == 0)
		answer.push_back(s);
	else
	{
		for (int i = 0; i < num.size(); ++i)
		{
			if (erased[i])
				continue;
			string s0 = s + to_string(num[i]) + " ";
			erased[i] = true;
			recursive(s0, m - 1, num, erased);
			erased[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> num(n);
	for (int i = 0; i < n; ++i)
		cin >> num[i];

	sort(num.begin(), num.end());

	vector<bool> erased(n, false);
	recursive("", m, num, erased);

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