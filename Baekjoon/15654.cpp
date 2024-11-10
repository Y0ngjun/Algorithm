#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void recursive(string s, int m, vector<int>& num, vector<bool>& erased)
{
	if (m == 0)
		cout << s << '\n';
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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> num(n);
	vector<bool> erased(n, false);
	for (int i = 0; i < n; ++i)
		cin >> num[i];

	sort(num.begin(), num.end());

	recursive("", m, num, erased);

	return 0;
}