#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int n, x, y;
		cin >> n >> x >> y;

		int max_v = 0;
		for (int j = 0; j < n - 1; ++j)
		{
			int v;
			cin >> v;
			max_v = max(max_v, v);
		}

		int my_v;
		cin >> my_v;

		if (my_v > max_v)
			cout << "0\n";
		else if (((double)(x - y) / my_v + 1 >= (double)x / max_v))
			cout << "-1\n";
		else
		{
			double ans = x - (double)my_v * ((double)x / max_v - 1);
			if (fabs(ans - std::round(ans)) < numeric_limits<double>::epsilon())
				ans += 1;
			else
				ans = ceil(ans);

			cout << ans << '\n';
		}
	}

	return 0;
}