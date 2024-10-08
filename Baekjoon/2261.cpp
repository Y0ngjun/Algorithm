#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;

// 거리 제곱을 계산하는 함수
long long distSquared(pair<int, int>& p1, pair<int, int>& p2) {
    long long dx = p1.first - p2.first;
    long long dy = p1.second - p2.second;
    return dx * dx + dy * dy;
}

long long ClosetPair(vector<pair<int, int>>& dots, vector<pair<int, int>>& strip, int start, int end)
{
    // 점이 3개 이하일 때
    if (end - start <= 2)
    {
        long long minDistSquared = LLONG_MAX;
        for (int i = start; i < end; ++i)
        {
            for (int j = i + 1; j <= end; ++j)
            {
                long long distSq = distSquared(dots[i], dots[j]);
                if (distSq < minDistSquared)
                    minDistSquared = distSq;
            }
        }
        return minDistSquared;
    }

    // 점이 4개 이상일 때
    int mid = (start + end) / 2;
    long long leftMin = ClosetPair(dots, strip, start, mid);
    long long rightMin = ClosetPair(dots, strip, mid + 1, end);
    long long minDistSquared = min(leftMin, rightMin);

    // 중간 영역 처리
    strip.clear();
    for (int i = start; i <= end; ++i)
    {
        if (abs(dots[i].first - dots[mid].first) * abs(dots[i].first - dots[mid].first) < minDistSquared)
            strip.push_back(dots[i]);
    }

    sort(strip.begin(), strip.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
        });

    // Y축 기준으로 거리가 가까운 점들만 비교
    for (int i = 0; i < strip.size(); ++i)
    {
        for (int j = i + 1; j < strip.size() && (strip[j].second - strip[i].second) * (strip[j].second - strip[i].second) < minDistSquared; ++j)
        {
            long long distSq = distSquared(strip[i], strip[j]);
            if (distSq < minDistSquared)
                minDistSquared = distSq;
        }
    }

    return minDistSquared;
}

int main()
{
    // 입력 크기 n
    int n;
    cin >> n;

    // 점 입력
    vector<pair<int, int>> dots(n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d", &dots[i].first, &dots[i].second);
    }

    // 점이 1개일 때
    if (n == 1)
    {
        printf("0.000000");
        return 0;
    }

    // 정렬 (X축 기준)
    sort(dots.begin(), dots.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
        });

    // 중간 영역을 저장할 벡터
    vector<pair<int, int>> strip;

    // 최근접 쌍 찾기
    long long minDistSquared = ClosetPair(dots, strip, 0, n - 1);

    // 출력
    printf("%lld", minDistSquared);

    return 0;
}