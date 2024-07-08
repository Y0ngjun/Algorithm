#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <ctime>

using namespace std;

int main() {
	time_t now = time(0);
	tm* ltm = localtime(&now);
	cout << 1900 + ltm->tm_year << "-";
	if ((1 + ltm->tm_mon) < 10)
		cout << 0;
	cout << 1 + ltm->tm_mon << "-";
	if (ltm->tm_mday < 10)
		cout << 0;
	cout << ltm->tm_mday << endl;
	return 0;
}