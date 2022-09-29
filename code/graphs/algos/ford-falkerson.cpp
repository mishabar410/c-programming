#include <bits/stdc++.h> //2783
using namespace std;

#define ll long long
#define INF 1000000000

vector<vector<int>> G;
vector<vector<int>> f;
vector<vector<int>> c;
vector<int> used;

int dfs(int u, int Cmin);
int t;
int main()
{
  int n, m;
  cin >> n >> m;
  G.resize(n, vector<int> ());
  f.resize(n, vector<int> (n, 0));
  c.resize(n, vector<int> (n, 0));
  used.resize(n, 0);
  t = n - 1;
  int from, to, cap;
  for (int i = 0; i < m; i++)
  {
    cin >> from >> to >> cap;
    G[from - 1].push_back(to - 1);
    G[to - 1].push_back(from - 1);

    c[from - 1][to - 1] = cap;
  }
  ll ans = 0;
  while(true)
  {
    int tmp = dfs(0,INF);
    if(tmp == 0)
      break;
    else
      ans += tmp;
    fill(used.begin(), used.end(), false);
  }
  cout << ans;
  return 0;
}

int dfs(int u, int Cmin)
{
  if (u == t) return Cmin;
  used[u] = 1;
  int delta = 0;
  for(auto v: G[u])
  {
    if ((used[v] == 0) && (f[u][v] < c[u][v]))
    {
      delta += dfs(v, min(Cmin, c[u][v] - f[u][v]));
      if (delta > 0)
      {
        f[u][v] += delta;
        f[v][u] -= delta;
        return delta;
      }
    }
  }
  return 0;
}
