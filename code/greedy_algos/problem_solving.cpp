#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000

int main() {
    ll n, a;
    cin >> n >> a;
    vector<pair<ll, ll>> problems;
    for (ll i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        problems.push_back({x, y});
    }
    sort(problems.begin(), problems.end());
    for (ll i = 0; i < n; i++)
    {
        if (a >= problems[i].first) a += problems[i].second;
        else
        {
            cout << i;
            return 0;
        }
    }
    cout << n;
    return 0;
}
