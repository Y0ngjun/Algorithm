#include <iostream>

using namespace std;

int main() {
	int N;
	int sum(1);
	cin >> N;
	for (int i = 1; i <= N; i++)
		sum *= i;
	cout << sum;
	return 0;
}