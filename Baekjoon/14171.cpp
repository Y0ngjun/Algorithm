#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n; // 1 <= n <= 200000

	unordered_map<string, unordered_multiset<string>> states; // ST, {city1, city2, ... }
	for (int i = 0; i < n; ++i)
	{
		string city, state;
		cin >> city >> state;
		states[state].insert(city);
	}

	int count = 0;
	for (auto& [state, cities] : states) // �ָ� ��ȸ
	{
		for (auto& city : cities) // ���ø� ��ȸ
		{
			if (city.substr(0, 2) == state)
				continue;
			for (auto& c : states[city.substr(0, 2)]) // ������ �ձ��ڷ� �����ϴ� �ֿ�
				if (c.substr(0, 2) == state) // ���� �ձ��ڷ� �����ϴ� ���ð� �ִ��� Ȯ��
				{
					++count;
				}
		}
	}
	cout << count / 2;
	return 0;
}
