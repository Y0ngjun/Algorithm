#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	int prev;
	cin >> prev;
	int now;
	cin >> now;
	int GCD = now - prev;
	vector<int> sub;
	sub.push_back(GCD);

	prev = now;

	for (int i = 0; i < n - 2; ++i)
	{
		cin >> now;
		sub.push_back(now - prev);
		GCD = gcd(GCD, now - prev);
		prev = now;
	}

	int sum = 0;

	for (int i : sub)
	{
		sum += i / GCD - 1;
	}

	cout << sum;

	return 0;
}