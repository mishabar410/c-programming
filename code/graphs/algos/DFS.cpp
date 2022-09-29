#include <bits/stdc++.h>

using namespace std;

void dfs(int, const vector<vector<int>>&);
vector<bool> vis(0);

vector<bool> Color(0);

void shortDFS(vector <vector<int> > & G, int cur);

int main()
{
    int n, m;
    cin >> n >> m;

    //иницилизируем список смежности и массив посещенных вершин
    vector<vector<int>> adj_list(n, vector<int>());
    vis.resize(n, false);
    Color.resize(n, 0);
    //ввод ребер
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj_list[x - 1].push_back(y - 1);
        adj_list[y - 1].push_back(x - 1);
    }
    cout << endl;

    dfs(0, adj_list); //поиск в глубину

    shortDFS(adj_list, 0);

    return 0;
}

void dfs(int u, const vector<vector<int>>& matrix_adjacency) {
    vis[u] = true;
    cout << "in " << u + 1 << endl;
    for(auto i : matrix_adjacency[u])
        if(!vis[i]) dfs(i, matrix_adjacency);
    cout << "out " << u + 1 << endl;
}

// Заменив значение Color[cur] = i можно считать компоненты связности
void shortDFS(vector <vector<int> > & G, int cur, vector<int> & Color)
{
    Color[cur] = 1;
    for (auto x : G[cur])
    {
        if (Color[x] == 0) shortDFS(G, x);
    }
    return;
}
