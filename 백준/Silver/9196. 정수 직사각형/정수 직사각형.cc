// BOJ 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<int, pair<int, int>>> recs;

    for (int w = 1; w <= 150; w++) {
        for (int h = 1; h < w; h++) {
            int d = w * w + h * h;
            recs.push_back({ d, { h , w } });
        }
    }

    std::sort(recs.begin(), recs.end());

    vector<vector<int>> idx(151, vector<int>(151));
    for (int i = 0; i < recs.size(); i++) {
        const auto& rec = recs[i];
        idx[rec.second.first][rec.second.second] = i;
    }

    while (true) {
        int h, w;
        cin >> h >> w;

        if (h == 0 && w == 0)
            break;

        cout << recs[idx[h][w] + 1].second.first << ' ' << recs[idx[h][w] + 1].second.second << '\n';
    }

    return 0;
}
