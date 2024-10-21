#include <iostream>
#include <string>

using namespace std;

int main() {
	int n, m, cnt = 0;
	string s;
	cin >> n >> m >> s;

	int cmp_len = 1 + 2 * n;
	bool prev_cmp = false;

	for (int i = 0; i < m - 1;)
	{
		if (prev_cmp)
		{
			if (s[i] == 'O' && s[i + 1] == 'I')
			{
				++cnt;
				i += 2;
			}
			else
			{
				prev_cmp = false;
			}
		}
		else
		{
			bool is_crt = true;

			for (int j = 0; j < cmp_len; ++j)
			{
				if (j % 2 == 0)
				{
					if (s[i + j] != 'I')
					{
						is_crt = false;
						i += j + 1;
						break;
					}
				}
				else
				{
					if (s[i + j] != 'O')
					{
						is_crt = false;
						i += j;
						break;
					}
				}
			}

			if (is_crt)
			{
				++cnt;
				prev_cmp = true;
				i += cmp_len;
			}
		}
	}
	cout << cnt;
	return 0;
}
