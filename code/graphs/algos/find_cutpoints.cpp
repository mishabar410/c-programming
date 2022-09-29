#include <bits/stdc++.h>

using namespace std;

vector<bool> Color(0);
int timer = 0;
vector<int> tin(0);
vector<int> fup(0);
vector<int> is_cutpoint(0);
void DFS(vector <vector<int> > & G, int cur, int b, int count);

void shortDFS(vector <vector<int> > & G, int cur, int p = -1)
{
    Color[cur] = 1;
    tin[cur] = fup[cur] = timer++;
    int children = 0;
    for (int i = 0; i < G[cur].size(); i++)
    {
        int to = G[cur][i];
        if (to == p) continue;
        if (Color[to]) fup[cur] = min (fup[cur], tin[to]);
        else
        {
            shortDFS(G, to, cur);
            fup[cur] = min (fup[cur], fup[to]);
            if (fup[to] >= tin[cur] && p != -1) is_cutpoint[cur] = 1;
            ++children;
        }
    }
    if (p == -1 && children > 1) is_cutpoint[cur] = 1;

}

int main()
{
    int n, m;
    cin >> n >> m;

    //иницилизируем список смежности и массив посещенных вершин
    vector<vector<int>> adj_list(n, vector<int>());
    Color.resize(n, 0);
    is_cutpoint.resize(n , 0);
    tin.resize(n, 1000000000);
    fup.resize(n, 1000000000);
    //ввод ребер
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj_list[x - 1].push_back(y - 1);
        adj_list[y - 1].push_back(x - 1);
    }

    shortDFS(adj_list, 0);

    int count;
    cin >> count;

    // vector<pair<int,int>> points(count);
    // for (int i = 0; i < count; i++){
    //     cin >> points[i].first >> points[i].first;


    int a, b, tmp;
    for (size_t i = 0; i < count; i++) {
        cin >> a >> b;
        Color.resize(n, 0);
        DFS(adj_list, a - 1, b - 1, -1);
    }
    return 0;
}

void DFS(vector <vector<int> > & G, int cur, int b, int count)
{
    Color[cur] = 1;
    if(is_cutpoint[cur]) count++;
    for (auto x : G[cur])
    {
        if (x == b) {
            cout << count;
            return;
        }
        if (Color[x] == 0) DFS(G, x, b, count);
    }
    // if(is_cutpoint[cur]) count--;
    return;
}

// Заменив значение Color[cur] = i можно считать компоненты связности
