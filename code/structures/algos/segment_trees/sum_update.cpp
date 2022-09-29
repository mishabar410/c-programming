#include <bits/stdc++.h> //3317
using namespace std;

#define ll long long
#define INF 1000000000

vector<ll> mas;
vector<ll> tree;
ll n, l;

void build (ll v, ll tl, ll tr);
ll sum (ll v, ll tl, ll tr, ll l, ll r);
void update (ll v, ll tl, ll tr, ll pos, ll new_val);

int main() {
    cin >> n;
    while ((1 << l) <= n)  ++l;
    l = pow(2, l);
    mas.assign(l, 0);
    tree.assign(4 * l, 0);
    for (ll i = 0; i < n; i++) cin >> mas[i];
    build(0, 0, l - 1);
    ll m;
    cin >> m;
    for (ll i = 0; i < m; i++)
    {
        ll left, right;
        string call;
        cin >> call;
        cin >> left >> right;
        if (call == "s") cout << sum (0, 0, l - 1, left - 1, right - 1) << endl;
        else update (0, 0, l - 1, left - 1, right);
    }
    return 0;
}

void build (ll v, ll tl, ll tr)
{
    if (tl == tr) tree[v] = mas[tl];
    else
    {
        ll tm = (tl + tr) / 2;
        build (v * 2 + 1, tl, tm);
        build (v * 2 + 2, tm + 1, tr);
        tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
    }
}

ll sum (ll v, ll tl, ll tr, ll l, ll r)
{
    if (l > r) return 0;
    if (l == tl && r == tr) return tree[v];
    ll tm = (tl + tr) / 2;
    return sum(v * 2 + 1, tl, tm, l, min(r, tm)) + sum(v * 2 + 2, tm + 1, tr, max(l, tm + 1), r);
}

void update (ll v, ll tl, ll tr, ll pos, ll new_val)
{
    if (tl == tr) tree[v] = new_val;
    else
    {
        ll tm = (tl + tr) / 2;
        if (pos <= tm) update (v * 2 + 1, tl, tm, pos, new_val);
        else update (v * 2 + 2, tm + 1, tr, pos, new_val);
        tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
    }
}
