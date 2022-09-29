#include <bits/stdc++.h>

using namespace std;

void shortDFS(vector <vector<int> > & G, int cur, int count);

int pos(int i, int j);
int n, m;
vector<int> Color(0);

int main() {
    int dots = 0;
    cin >> n >> m;
    vector<vector<char>> paper(m + 1, vector<char>(n + 1, 0));
    long long int size = n * m;
    vector<vector<int>> adj_list(size, vector<int>());
    Color.resize(size + 1, 0);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> paper[i][j];
            if (paper[i][j] == '.')
            {
                dots++;
                continue;
            }
            else
            {
                if (paper[i - 1][j] == '#'){
                    adj_list[pos(i, j)].push_back(pos(i - 1, j));
                    adj_list[pos(i - 1, j)].push_back(pos(i, j));
                }
                if (paper[i][j - 1] == '#'){
                    adj_list[pos(i, j)].push_back(pos(i, j - 1));
                    adj_list[pos(i, j - 1)].push_back(pos(i, j));
                }
            }
        }
    }
    int count = 1;
    for (int i = 0; i < n * m; i++)
    {
        if (Color[i] == 0){
            shortDFS(adj_list, i, count);
            count++;
        }
    }
    count--;
    cout << count - dots << endl;
    return 0;
}

void shortDFS(vector <vector<int> > & G, int cur, int count)
{
    Color[cur] = count;
    for (auto x : G[cur])
    {
        if (Color[x] != count) shortDFS(G, x, count);
    }
    return;
}

int pos(int i, int j)
{
    return (i - 1) * m + j - 1;
}
