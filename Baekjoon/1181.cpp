#include <string>
#include <vector>
#include <queue>
#include <iostream>

struct String
{
	std::string _str;

	String() = default;

	String(const std::string& str) : _str(str) {}

	bool operator<(const String& rhs) const
	{
		if (_str.size() == rhs._str.size())
			return _str < rhs._str;
		else
			return _str.size() < rhs._str.size();
	}

	bool operator>(const String& rhs) const
	{
		return rhs < *this;
	}
};

int main()
{
	int n;
	std::cin >> n;
	std::priority_queue<String, std::vector<String>, std::greater<String>> pq;
	for (int i = 0; i < n; ++i)
	{
		std::string str;
		std::cin >> str;
		pq.push(String{ str });
	}

	std::string prev = "";
	while (!pq.empty())
	{
		if (prev == pq.top()._str)
		{
			pq.pop();
			continue;
		}
		std::cout << pq.top()._str << '\n';
		prev = pq.top()._str;
		pq.pop();
	}
	return 0;
}