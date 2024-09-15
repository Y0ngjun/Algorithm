#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int n;
		cin >> n;

		map<string, set<string>> clothes;
		for (int j = 0; j < n; ++j)
		{
			string value, key;
			cin >> value >> key;
			if (clothes.find(key) != clothes.end())
				clothes[key].insert(value);
			else
				clothes[key] = { value };
		}

		int sum = 1;
		for (auto iter : clothes)
			sum *= (iter.second.size() + 1);

		cout << sum - 1 << '\n';
	}

	return 0;
}