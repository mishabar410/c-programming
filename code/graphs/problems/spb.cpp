#include <bits/stdc++.h> //113940

using namespace std;

const long long mod = 1e9 + 7;
const long long inf = 1e8;
const long long MAXN = 1000000;

#define debug_
#define all(x) x.begin(), x.end()

vector<pair<int, int>> g[100000];
int tin[100000], fup[100000];
char used[100000];
vector<pair<int, int>> ans;

void dfs(int v, int ed = -1, int p = -1)
{
	used[v] = 1;
    if (p == -1) tin[v] = 0;
    else tin[v] = tin[p] + 1;
	fup[v] = tin[v];
	for (auto& [u, e] : g[v])
	{
		if (used[u])
		{
			if (e != ed)
				fup[v] = min(fup[v], tin[u]);
			continue;
		}
		dfs(u, e, v);
		fup[v] = min(fup[v], fup[u]);
		if (fup[u] > tin[v])
			ans.push_back({ v + 1, u + 1 });
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    int n, m;
	cin >> n >> m;
	int count = 0;
	int timer = 0;
	if (m > 2 * n - 1)
	{
		cout << "! No" << endl;
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		int res = 0;
		while (count < 3 * n)
		{
			cout << "? " << i + 1 << endl;
			cin >> res;
			count++;
			if (res == -1) break;
			g[i].push_back({ res - 1, timer });
			g[res - 1].push_back({ i, timer++ });
		}
	}

	for (int v = 0; v < n; v++)	if (!used[v]) dfs(v);

	if (ans.size() >= (m + 1) / 2)
	{
		cout << "! Yes" << endl;
		for (auto& [v, u] : ans) cout << v << " " << u << endl;
	}
	else cout << "! No" << endl;

	return 0;
}
