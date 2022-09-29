#include <bits/stdc++.h> //111711
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back
#define f first
#define s second

int n, m, l, timer, root;
vector<bool> used;
vector<int> d, tin, tout;
vector<vector<int>> g, jmp;

void dfs(int v) {
    used[v] = true;
    tin[v] = timer++;
    for (int i = 1; i <= l; ++i) jmp[v][i] = jmp[jmp[v][i-1]][i-1];
    for (auto u : g[v])
        if (!used[u]) jmp[u][0] = v, dfs(u);
    tout[v] = timer++;
}

bool is_ancestor(int u, int v) {
    if (tin[u] <= tin[v] && tout[u] >= tout[v]) return true;
    return false;
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int k = l; k >= 0; --k) {
        if (!is_ancestor(jmp[u][k], v)) u = jmp[u][k];
    }
    return jmp[u][0];
}


int main() {
    while (true) {
        l = 0, timer = 0, root = 0;
        cin >> n;
        if (n == 0) return 0;
        while ((1 << l) <= n) ++l;
        tin.assign(n+1, 0), tout.assign(n+1, 0), used.assign(n+1, false);
        g.assign(n+1, vector<int>(0)), jmp.assign(n+1, vector<int>(l+5, 0));
        for (int i = 1; i < n; ++i) {
            int v, u;
            cin >> v >> u;
            --v, --u;
            g[v].PB(u), g[u].PB(v);
        }
        dfs(0);
        cin >> m;
        while (m--) {
            char ch;
            cin >> ch;
            if (ch == '!') {
                cin >> root;
                --root;
                continue;
            } else {
                int v, u;
                cin >> v >> u;
                --v, --u;
                int tmp1 = lca(v, u);
                int tmp2 = lca(v, root);
                int tmp3 = lca(u, root);
                cout << (tmp1^tmp2^tmp3) + 1 << endl;
            }
        }
    }
    return 0;
}
