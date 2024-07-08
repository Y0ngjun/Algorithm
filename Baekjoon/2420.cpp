#include <iostream>

using namespace std;

int main() {
	long long N, M;
	cin >> N >> M;
	cout << (N - M > 0 ? N - M : M - N);
	return 0;
}