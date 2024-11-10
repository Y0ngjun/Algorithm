#include <iostream>
#include <string>

using namespace std;

void recursive(string s, int n0, int n1, int m)
{
	if (m == 0)
		cout << s << '\n';
	else
	{
		for (int i = n0; i <= n1; ++i)
		{
			string s0 = s + to_string(i) + " ";
			recursive(s0, i, n1, m - 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	recursive("", 1, n, m);

	return 0;
}