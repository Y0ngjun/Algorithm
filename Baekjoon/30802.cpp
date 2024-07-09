#include <iostream>

using namespace std;

int main() {
	int n, size[6], t, p, tSum = 0;
	cin >> n;
	for (int i = 0; i < 6; i++) {
		cin >> size[i];
	}
	cin >> t >> p;
	for (int i = 0; i < 6; i++) {
		if (size[i] != 0)
			tSum += (size[i] - 1) / t + 1;
	}
	cout << tSum << endl;
	cout << n / p << ' ' << n % p;
	return 0;
}