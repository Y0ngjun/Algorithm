#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	unordered_map<string, string> sitePasswd;
	for (int i = 0; i < n; ++i)
	{
		string site;
		cin >> site;

		string passwd;
		cin >> passwd;

		sitePasswd[site] = passwd;
	}

	for (int i = 0; i < m; ++i)
	{
		string site;
		cin >> site;

		cout << sitePasswd[site] << '\n';
	}

	return 0;
}