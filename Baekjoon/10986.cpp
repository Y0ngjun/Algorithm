#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<int> modulus(m);
	modulus[0] = 1;

	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		sum = (sum + num) % m;
		modulus[sum] += 1;
	}

	long long answer = 0;
	for (int i = 0; i < m; ++i)
	{
		int mdl = modulus[i];
		if (mdl < 2)
			continue;
		answer += (long long)mdl * (mdl - 1) / 2;
	}

	cout << answer;

	return 0;
}
