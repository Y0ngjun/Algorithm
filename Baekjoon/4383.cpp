#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int n;
	while (cin >> n)
	{
		vector<int> jolly(n);
		for (int i = 0; i < n; ++i)
			cin >> jolly[i];
		vector<bool> mask(n);
		bool isJolly = true;
		for (int i = 0; i < n - 1; ++i)
		{
			int idx = abs(jolly[i] - jolly[i + 1]);
			if (idx > 0 && idx < n)
				mask[idx] = true;
			else
			{
				isJolly = false;
				break;
			}
		}
		for (int i = 1; i < n; ++i)
			if (mask[i] == false)
				isJolly = false;
		if (isJolly)
			cout << "Jolly" << '\n';
		else
			cout << "Not jolly" << '\n';
	}
	return 0;
}
