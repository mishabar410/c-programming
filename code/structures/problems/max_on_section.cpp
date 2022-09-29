#include <bits/stdc++.h> //3312
using namespace std;

#define ll long long
#define INF 1000000000

vector<int> a;
vector<int> sec_max;
vector<vector<int>> decomp;

int n, d, m;
int max_query(int x, int y);
int m_query(int x, int y, int val);

int main() {
    cin >> n;
    d = sqrt(n);
    m = n / d + 1;
    a.assign(n + 1, 0);
    sec_max.assign(m, 0);
    decomp.assign(m, vector<int> ());
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sec_max[i / d] = max(sec_max[i / d], a[i]);
        decomp[i / d].push_back(a[i]);
    }
    for (int i = 0; i < m; i++) sort(decomp[i].begin(), decomp[i].end());
    int k;
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        int ans1 = max_query(x - 1, y - 1);
        int ans2 = m_query(x - 1, y - 1, ans1);
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}

int max_query(int x, int y)
{
    int res = -INF;
    while (x % d && x <= y)  res = max(res, a[x]), x++;
    while (y % d != d - 1 && y >= x)  res = max(res, a[y]), y--;
    for (int i = x / d; i < (y + 1) / d; i++) res = max(res, sec_max[i]);
    return res;
}

int m_query(int x, int y, int val)
{
    int ans = 0;
    while (x % d && x <= y)
    {
        if (val == a[x]) ans++;
        x++;
    }
    while (y % d != d - 1 && y >= x)
    {
        if (val == a[y]) ans++;
        y--;
    }
    for (int i = x / d; i < (y + 1) / d; i++)
    {
        ans += upper_bound(decomp[i].begin(), decomp[i].end(), val) -
            lower_bound(decomp[i].begin(), decomp[i].end(), val);
    }
    return ans;
}
