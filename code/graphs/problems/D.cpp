#include <bits/stdc++.h>

using namespace std;

vector<int> Color(0);

int flag = 1;
void shortDFS(vector <vector<int> > & G, int cur);

int main() {
    int n, m;

    cin >> n >> m;
    //иницилизируем список смежности и массив посещенных вершин
    vector<vector<int>> adj_list(n, vector<int>());
    Color.resize(n + 1, 0);
    //ввод ребер
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj_list[x - 1].push_back(y - 1);
        adj_list[y - 1].push_back(x - 1);
    }

    for(int i = 0; i < n; i++){
        if (Color[i] == 0){
            Color[i] = 1;
            shortDFS(adj_list, i);
        }
    }
    if(flag) {
        cout << "YES" << endl;
        for(int i = 0; i < n; i++){
            if (Color[i] == 1) cout << i + 1 << " ";
        }
    }
    else cout << "NO";
    return 0;
}

void shortDFS(vector <vector<int> > & G, int cur)
{
    for (auto x : G[cur])
    {
        if (Color[x] == Color[cur]) {
            flag = 0;
            return;
        }
        if (Color[x] == 0) {
            Color[x] = Color[cur] * (-1);
            shortDFS(G, x);
        }
    }
    return;
}
