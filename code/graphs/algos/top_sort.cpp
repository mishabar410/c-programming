#include <bits/stdc++.h>

using namespace std;

int n; // число вершин
vector<int> g[MAXN]; // граф
vector<char> used;
vector<int> ans;

int main() {
    int n;
	int m;
    cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a - 1].push_back (b - 1);
		g[b - 1].push_back (a - 1);
	}

	used.assign (n, false);

    topological_sort();
	// for (int i=0; i<n; ++i)
	// 	if (!used[i])
	// 		dfs1 (i);
    return 0;
}

void dfs (int v) {
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (!used[to])
			dfs (to);
	}
	ans.push_back (v);
}

void topological_sort() {
	for (int i=0; i<n; ++i)
		used[i] = false;
	ans.clear();
	for (int i=0; i<n; ++i)
		if (!used[i])
			dfs (i);
	reverse (ans.begin(), ans.end());
