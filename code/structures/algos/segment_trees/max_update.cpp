#include <bits/stdc++.h> //3316 
using namespace std;

#define ll long long
#define INF 1000000000

ll n, l;

vector<ll> mas;
vector<pair<ll, ll>> tree;

pair<ll, ll> combine (pair<ll, ll> a, pair<ll, ll> b);
void build (ll v, ll tl, ll tr);
pair<ll, ll> get_max (ll v, ll tl, ll tr, ll l, ll r); //первый элемент пары это максимальный элемент отрезка, а второй - количество вхождений
void update (ll v, ll tl, ll tr, ll pos, ll new_val);

int main() {
    cin >> n;
    while ((1 << l) < n)  ++l;
    l = pow(2, l);
    mas.assign(l, -INF);
    tree.assign(4 * l, make_pair (-INF, 0));
    for (ll i = 0; i < n; i++) cin >> mas[i];
    ll m;
    cin >> m;
    build(0, 0, l - 1);
    for (ll i = 0; i < m; i++)
    {
        ll left, right;
        string call;
        cin >> call;
        cin >> left >> right;
        if (call == "s") cout << get_max(0, 0, l - 1, left - 1, right - 1).first << endl;
        else update (0, 0, l - 1, left - 1, right);
        cout << endl;
    }
    return 0;
}

pair<ll, ll> combine (pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first > b.first) return a;
    if (b.first > a.first) return b;
    return make_pair (a.first, a.second + b.second);
}

void build (ll v, ll tl, ll tr)
{
    if (tl == tr) tree[v] = make_pair (mas[tl], 1);
    else
    {
        ll tm = tl + (tr - tl) / 2;
        build (v * 2 + 1, tl, tm);
        build (v * 2 + 2, tm + 1, tr);
        tree[v] = combine (tree[v * 2 + 1], tree[v * 2 + 2]);
    }
}

pair<ll, ll> get_max (ll v, ll tl, ll tr, ll l, ll r)
{
    if (l > r) return make_pair (-INF, 0);
    if (l == tl && r == tr) return tree[v];
    ll tm = (tl + tr) / 2;
    return combine (get_max (v * 2 + 1, tl, tm, l, min (r, tm)),
                    get_max (v * 2 + 2, tm + 1, tr, max(l, tm + 1), r));
}

void update (ll v, ll tl, ll tr, ll pos, ll new_val)
{
    if (tl == tr) tree[v] = make_pair (new_val, 1);
    else
    {
        ll tm = (tl + tr) / 2;
        if (pos <= tm) update (v * 2 + 1, tl, tm, pos, new_val);
        else update (v * 2 + 2, tm + 1, tr, pos, new_val);
        tree[v] = combine (tree[v * 2 + 1], tree[v * 2 + 2]);
    }
}
