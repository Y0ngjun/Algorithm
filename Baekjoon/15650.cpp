#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> num(n);
	iota(num.begin(), num.end(), 1);
	set<set<int>> pm;
	do
	{
		set<int> temp;
		for (int i = 0; i < m; ++i)
			temp.insert(num[i]);
		pm.insert(temp);
	} while (next_permutation(num.begin(), num.end()));

	for (auto ss : pm)
	{
		for (auto s : ss)
			cout << s << ' ';
		cout << '\n';
	}

	return 0;
}
