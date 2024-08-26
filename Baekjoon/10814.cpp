#include <string>
#include <vector>
#include <queue>
#include <iostream>

struct Person
{
	int _AGE;
	std::string _NAME;
	int _ORDER;

	Person(const int& age, const std::string& name, const int& order)
		: _AGE(age), _NAME(name), _ORDER(order)
	{

	}

	bool operator > (const Person& person) const
	{
		if (_AGE == person._AGE)
		{
			return _ORDER > person._ORDER;
		}
		else
		{
			return _AGE > person._AGE;
		}
	}
};

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	std::priority_queue<Person, std::vector<Person>, std::greater<Person>> persons;
	for (int i = 0; i < n; ++i)
	{
		int age;
		std::string name;
		std::cin >> age >> name;
		persons.push(Person(age, name, persons.size()));
	}

	for (int i = 0; i < n; ++i)
	{
		std::cout << persons.top()._AGE << ' ' << persons.top()._NAME << '\n';
		persons.pop();
	}

	return 0;
}