#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<char> isPrime(10000000, true);
unordered_set<int> visited;
int ans = 0;

void make_perm(const string& temp, string& num, vector<bool>& selected)
{
	if (temp.size() == num.size())
	{
		int p = stoi(num);
		if (isPrime[p] && visited.count(p) == 0)
		{
			visited.insert(p);
			ans += 1;
		}
	}
	else
	{
		for (int i = 0; i < temp.size(); ++i)
		{
			if (!selected[i])
			{
				selected[i] = true;
				num.push_back(temp[i]);
				make_perm(temp, num, selected);
				selected[i] = false;
				num.pop_back();
			}
		}
	}
}

void check_prime(const string& temp)
{
	string num = "";
	vector<bool> selected(temp.size(), false);
	make_perm(temp, num, selected);
}

void make_comb(const string& num, string& temp, int size, int start)
{
	if (temp.size() == size)
	{
		check_prime(temp);
	}
	else
	{
		for (int i = start; i <= num.size() - (size - temp.size()); ++i)
		{
			temp.push_back(num[i]);
			make_comb(num, temp, size, i + 1);
			temp.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	isPrime[0] = isPrime[1] = false;
	for (int i = 4; i < 10000000; i += 2)
		isPrime[i] = false;
	for (int i = 3; i < 10000000; i += 2)
	{
		if (isPrime[i])
		{
			for (long long j = 1LL * i * i; j < 10000000; j += 2 * i)
				isPrime[j] = false;
		}
	}

	int test;
	cin >> test; // <=200

	for (int t = 0; t < test; ++t)
	{
		visited.clear();
		string num;
		cin >> num;

		sort(num.begin(), num.end());

		ans = 0;

		for (int i = 1; i <= num.size(); ++i)
		{
			string temp = "";
			make_comb(num, temp, i, 0);
		}

		cout << ans << '\n';
	}

	return 0;
}
