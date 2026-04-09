// BOJ 32754. 손이 닿는 범위
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // R + C(대각선 길이의 절반) >= D(중심까지의 길이)

    int N;
    double R;
    cin >> N >> R;

    int answer = 0;

    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        double C = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3)) / 2;
        double D = sqrt((x1 + x3) * (x1 + x3) + (y1 + y3) * (y1 + y3)) / 2;

        if (R + C >= D)
            answer++;
    }

    cout << answer;

    return 0;
}
