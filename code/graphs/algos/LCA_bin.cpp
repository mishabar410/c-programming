#include <bits/stdc++.h> //111796
using namespace std;

#define ll long long
#define INF 1000000000

ll n, m, l, x, y, z, timer, ans, res, a1, a2;
vector <vector<ll>> g;
vector<ll> tin, tout;
vector <vector<ll>> up;

void dfs (int v, int p = 0)
{
  tin[v] = ++timer;
  up[v][0] = p;
	for (int i = 1; i <= l; ++i) up[v][i] = up[up[v][i-1]][i-1];
	for (size_t i = 0; i < g[v].size(); ++i)
  {
	  int to = g[v][i];
		if (to != p) dfs (to, v);
	}
	tout[v] = ++timer;
}

bool upper (int a, int b)
{
	return (tin[a] <= tin[b]) && (tout[a] >= tout[b]);
}

int lca (int a, int b)
{
	if (upper (a, b))  return a;
	if (upper (b, a))  return b;
	for (int i = l; i >= 0; --i)
  {
    if (! upper (up[a][i], b)) a = up[a][i];
  }
  return up[a][0];
}


int main() {
  cin >> n >> m;
  while ((1 << l) <= n)  ++l;
  tin.assign(n+1, 0), tout.assign(n+1, 0);
  g.assign(n+1, vector<ll>(0)), up.assign(n+1, vector<ll>(l+5, 0));
  for (int i = 1; i < n; i++)
  {
    int v;
    cin >> v;
    g[v].push_back(i);
    g[i].push_back(v);
  }

  for (int i = 0; i < n; ++i)  up[i].resize(l + 1);
  dfs (0);

  cin >> a1 >> a2 >> x >> y >> z;
  for (int i = 0; i < m; i++)
  {
    res = lca((a1 + res) % n, a2);
    ans += res;
    a1 = (x * a1 + y * a2 + z) % n;
    a2 = (x * a2 + y * a1 + z) % n;
  }
  cout << ans << endl;

  return 0;
}
