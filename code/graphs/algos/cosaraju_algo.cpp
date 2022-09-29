#include <bits/stdc++.h>

using namespace std;

vector < vector<int> > g, gr;
vector<char> used;
vector<int> order, component;

void dfs1 (int v);
void dfs2 (int v);
// поиск компонент сильной связности
int main() {
	int n;
	int m;
    cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back (b);
		gr[b].push_back (a);
	}

	used.assign (n, false);
	for (int i=0; i<n; ++i)
		if (!used[i])
			dfs1 (i);
	used.assign (n, false);
	for (int i=0; i<n; ++i) {
		int v = order[n-1-i];
		if (!used[v]) {
			dfs2 (v);
			cout << v;
			component.clear();
		}
	}
    return 0;
}

void dfs1 (int v) {
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i) // почему счет идет с 0 если заполняем с 1
		if (!used[ g[v][i] ])
			dfs1 (g[v][i]);
	order.push_back(v);
}

void dfs2 (int v) {
	used[v] = true;
	component.push_back (v);
	for (size_t i=0; i<gr[v].size(); ++i)
		if (!used[ gr[v][i] ])
			dfs2 (gr[v][i]);
}
