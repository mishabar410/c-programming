#include <bits/stdc++.h> //113785
using namespace std;     //Количество элементов < x и инкремент на отрезке
                         // медленное говно
#define ll long long
#define INF 1000000000

vector<ll> a;
vector<ll> tree;

ll h, n, m;

void build (ll v, ll tl, ll tr);
void add (ll v, ll tl, ll tr, ll l, ll r, ll num);
ll find (ll v, ll tl, ll tr, ll pos);
ll ans (ll l, ll r, ll num);

int main() {
    cin >> n >> m;
    while ((1 << h) < n) ++h;
    h = pow(2, h);
    tree.assign(4 * h, 0);
    a.assign(h, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    int x;
    ll left, right, num;
    build(0, 0, h - 1);
    for (int i = 0; i < m; i++)
    {
        cin >> x >> left >> right >> num;
        if (x == 1)
        {
            cout << ans (left - 1, right - 1, num) << endl;
        }
        else add (0, 0, h - 1, left - 1, right - 1, num);
    }
    return 0;
}

void build (ll v, ll tl, ll tr)
{
    if (tl == tr) tree[v] = a[tl];
    else
    {
        ll tm = tl + (tr - tl) / 2;
        build (v * 2 + 1, tl, tm);
        build (v * 2 + 2, tm + 1, tr);
    }
}

void add (ll v, ll tl, ll tr, ll l, ll r, ll num)
{
    if (l > r) return;
    if (l == tr && r == tr)
    {
        tree[v] += num;
    }
    if (l == r) return;
    ll tm = tl + (tr - tl) / 2;
    add (v * 2 + 1, tl, tm, l, min (r, tm), num);
    add (v * 2 + 2, tm + 1, tr, max (l, tm + 1), r, num);
}

ll find (ll v, ll tl, ll tr, ll pos)
{
    if (tl == tr) return tree[v];
    ll tm = tl + (tr - tl) / 2;
    if (pos <= tm) return tree[v] + find (v * 2 + 1, tl, tm, pos);
    else return tree[v] + find (v * 2 + 2, tm + 1, tr, pos);
}

ll ans (ll l, ll r, ll num)
{
    vector<ll> mas;
    for (int i = l; i <= r; i++) mas.push_back(find (0, 0, h - 1, i));
    sort(mas.begin(), mas.end());
    return lower_bound(mas.begin(), mas.end(), num) - mas.begin();
}
