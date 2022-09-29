#include <bits/stdc++.h> //113904
using namespace std;

#define ll long long
#define INF 1000000000

vector<int> times;              //СТО ТЫСЯЧ ЧАСОВ
vector<vector<int>> or_g(1000000);
vector<vector<int>> or_g_reversed(1000000);
vector<vector<int>> cond_g(1000000);
vector<int> Color;
vector<int> order;
vector<vector<int>> component(1000000);


void dfs_cosaraju_1 (int cur);
void dfs_cosaraju_2 (int cur, int number_of_component);

void cond_dfs(int number_of_component);
void shortDFS(int cur);

int n, m, h, tmp = 99;
int minimal = 1000000;

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    int number_of_component = 1;
    cin >> n >> m >> h;
    times.resize(n);
    Color.resize(n, 0);
    for (int i = 0; i < n; i++) cin >> times[i];
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if ((times[x] + 1) % h == times[y])
        {
            or_g[x - 1].push_back(y - 1);
            or_g_reversed[y - 1].push_back(x - 1);
        }
        if ((times[y] + 1) % h == times[x])
        {
            or_g[y - 1].push_back(x - 1);
            or_g_reversed[x - 1].push_back(y - 1);
        }
    }

    for (int i = 0; i < n; i++) if (!Color[i]) dfs_cosaraju_1(i);

    Color.assign(n, 0);

    for (int i = 0; i < n; i++)
    {
        int v = order[n - i - 1];
        if (!Color[v])
        {
            dfs_cosaraju_2 (v, number_of_component);
            number_of_component++;
        }
    }

    for (int i = 1; i < number_of_component; i++) cond_dfs(i);

    Color.assign(n, 0);

    for (int i = 1; i < number_of_component; i++) if (!Color[i]) shortDFS(i);

    cout << minimal << endl << endl;
    // cout << "yo" << endl;
    for (int i = 0; i < number_of_component - 1; i++) cout << cond_g[i][0];
    // cout << cond_g[i][0] << "!";
    // cout << "y1o" << endl;
    for (int j = 0; j < component[tmp].size(); j++) cout << component[tmp][j] + 1 << " ";

    return 0;
}

void cond_dfs(int number_of_component)
{
    for (int i = 1; i < number_of_component; i++)
    {
        // cout << "yo" << endl;
        for (int j = 0; j < component[i].size(); j++)
        {
            int num = component[i][j];
            cout << "yo1" << endl << or_g[num].size() << endl;
            for (int z = 0; z < or_g[num].size(); z++)
            {
                cond_g[i - 1].push_back(or_g[num][z]);
                cout << "yo" << endl;
            }
        }
    }
}

void shortDFS(int cur)
{
    Color[cur] = 1;
    for (int i = 0; i < cond_g[cur].size(); i++)
    {
        if (!Color[cond_g[cur][i]]) shortDFS(cond_g[cur][i]);
    }
    if (cond_g[cur].empty())
    {
        if (minimal < component[cur + 1].size())
        {
            minimal = component[cur + 1].size();
            tmp = cur + 1;
        }
    }
}

void dfs_cosaraju_1 (int cur) {
    Color[cur] = 1;
    for (auto x : or_g[cur]) if (!Color[x]) dfs_cosaraju_1(x);
    order.push_back(cur);
    return;
}

void dfs_cosaraju_2 (int cur, int number_of_component) {
    Color[cur] = number_of_component;
	component[number_of_component].push_back(cur);
    cout << cur << endl;
	for (auto x : or_g_reversed[cur]) if (!Color[x]) dfs_cosaraju_2 (x, number_of_component);
    return;
}
