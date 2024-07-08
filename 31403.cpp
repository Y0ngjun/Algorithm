#include <iostream>
#include <string>

using namespace std;

int main() {
	int A, B, C;
	cin>> A >> B >> C;
	cout << A + B - C << endl;
	cout << stoi(to_string(A) + to_string(B)) - C << endl;
	return 0;
}