#include <bits/stdc++.h> //2917
using namespace std;

#define ll long long
#define INF 1000000000

vector<vector<int>> G;
vector<vector<int>> f;
vector<int> used;

int shortDFS(int cur, int Cmin);
int n;
int main()
{
  cin >> n;
  G.resize(n + 2, vector<int> ());
  f.resize(n + 2, vector<int> (n + 2, 0));
  used.resize(n + 2, 0);
  int m;
  string tmp;
  for (int i = 1; i <= n; i++)
  {
    cin >> m;
    for (int j = 0; j < m; j++)
    {
      cin >> tmp;
      if (tmp == "school")
      {
        G[0].push_back(i);
        G[i].push_back(0);
      }
      else if (tmp == "station")
      {
        G[n + 1].push_back(i);
        G[i].push_back(n + 1);
      }
      else
      {
        int p = atoi(tmp.c_str());
        G[i].push_back(p);
        G[p].push_back(i);
      }
    }
  }
  ll ans = 0;
  int d;
  while (d)
  	{
  		used.assign(n + 2, false);
  		d = shortDFS(0, 3);
  		ans += d;
  	}
  cout << ans;
  return 0;
}

int shortDFS(int cur, int Cmin)
{
  if (cur == n + 1) return Cmin;
  used[cur] = 1;
    for (auto i : G[cur])
    {
        if (!used[i] && f[cur][i] < 1)
        {
          int tmp = shortDFS(i, min(1 - f[cur][i], Cmin));
          if (tmp > 0)
          {
            f[cur][i] += tmp;
            return tmp;
          }
        }
    }
    return 0;
}
