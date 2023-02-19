#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define INF 1000000000

ld find_area(pair<ld, ld> a, pair<ld, ld> b, pair<ld, ld> c)
{
    pair<ld, ld> vector_1;
    pair<ld, ld> vector_2;

    vector_1.first = c.first - b.first;
    vector_1.second = c.second - b.second;

    vector_2.first = a.first - b.first;
    vector_2.second = a.second - b.second;

    return (vector_1.first * vector_2.second -
            vector_2.first * vector_1.second) / 2;
}

int main() {
    vector<pair<ld, ld>> dots(501);
    vector<ld> dp(501, -1 * INF);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        dots[i].first = cos(2 * M_PI * i / n) / (2 * sin(M_PI / n));
        dots[i].second = sin(2 * M_PI * i / n) / (2 * sin(M_PI / n));
    }
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = find_area(dots[0], dots[1], dots[2]);
    for (int l = 3; l < n; l++)
    {
        for (int i = 1; i < l; i++)
        {
            dp[l] = max(dp[l], dp[i] + dp[l - i - 1]);
            dp[l] = max(dp[l], find_area(dots[0], dots[i], dots[l]) +
                        dp[abs(l - i - 2)] + dp[abs(i - 2)]);
        }
    }
    cout << dp[n - 1];
    return 0;
}
