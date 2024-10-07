#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string num;
	cin >> num;

	int count = 0;
	vector<int> set(10, 0);

	for (const char& c : num)
	{
		int idx = c - '0';
		if (idx == 6 || idx == 9)
		{
			if (set[6] == 0 && set[9] == 0)
			{
				for (int& i : set)
					++i;
				++count;
			}
			if (set[6])
				--set[6];
			else
				--set[9];
		}
		else
		{
			if (set[idx] == 0)
			{
				for (int& i : set)
					++i;
				++count;
			}
			--set[idx];
		}
	}
	cout << count;
	return 0;
}