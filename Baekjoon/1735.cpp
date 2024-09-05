#include <iostream>
#include <numeric>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a1, a2, b1, b2;
	cin >> a1 >> b1 >> a2 >> b2;

	int a = a1 * b2 + a2 * b1;
	int b = b1 * b2;

	int GCD = gcd(a, b);

	cout << a / GCD << ' ' << b / GCD;

	return 0;
}