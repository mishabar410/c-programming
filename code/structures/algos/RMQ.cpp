#include <bits/stdc++.h> //752
using namespace std;

#define ll long long
#define INF 1000000000

vector<int> a;
vector<pair<int, int>> sec_max;

int n, d, m;
pair<int, int> max_query(int x, int y);

int main() {
    cin >> n;
    d = sqrt(n);
    m = n / d + 1;
    a.assign(n + 1, 0);
    sec_max.assign(m, pair<int, int> (-INF, -1));
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > sec_max[i / d].first)
        {
            sec_max[i / d].first = a[i];
            sec_max[i / d].second = i;
        }
    }
    int k;
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        pair<int, int> ans = max_query(x - 1, y - 1);
        cout << ans.first << " " << ans.second << endl;
    }
    return 0;
}

pair<int, int> max_query(int x, int y)
{
    pair<int, int> res;
    res.first = -INF;
    res.second = -1;
    while (x % d && x <= y)
    {
        if (a[x] > res.first)
        {
            res.first = a[x];
            res.second = x + 1;
        }
        x++;
    }
    while (y % d != d - 1 && y >= x)
    {
        if (a[y] > res.first)
        {
            res.first = a[y];
            res.second = y + 1;
        }
        y--;
    }
    for (int i = x / d; i < (y + 1) / d; i++)
    {
        if (sec_max[i].first > res.first)
        {
            res.first = sec_max[i].first;
            res.second = sec_max[i].second + 1;
        }
    }
    return res;
}
