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
	for (auto& [state, cities] : states) // 주를 순회
	{
		for (auto& city : cities) // 도시를 순회
		{
			if (city.substr(0, 2) == state)
				continue;
			for (auto& c : states[city.substr(0, 2)]) // 도시의 앞글자로 시작하는 주에
				if (c.substr(0, 2) == state) // 주의 앞글자로 시작하는 도시가 있는지 확인
				{
					++count;
				}
		}
	}
	cout << count / 2;
	return 0;
}
