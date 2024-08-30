#include <vector>
#include <iostream>

struct Person
{
	int height;
	int weight;
	int count;
	Person()
		:count(1)
	{}
};

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	std::vector<Person> vec(n);

	for (Person& person : vec)
	{
		int height, weight;
		std::cin >> person.height >> person.weight;
	}

	for (Person& person : vec)
	{
		for (const Person& p : vec)
		{
			if (person.height < p.height && person.weight < p.weight)
				person.count++;
		}
		std::cout << person.count << ' ';
	}

	return 0;
}