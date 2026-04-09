// BOJ 
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int min_x = 1e9, min_y = 1e9;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        if (min_y > y || min_y == y && min_x > x) {
            min_x = x;
            min_y = y;
        }
    }

    int min_x2 = 1e9, min_y2 = 1e9;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        if (min_y2 > y || min_y2 == y && min_x2 > x) {
            min_x2 = x;
            min_y2 = y;
        }
    }

    cout << min_x2 - min_x << ' ' << min_y2 - min_y;

    return 0;
}
