#include <bits/stdc++.h>

using namespace std;

vector<int> Color(0);

void shortDFS(vector <vector<int> > & G, int cur, int i);

vector<vector<int>> list_comp(0, vector<int>());

int main() {
    int n, m;
    cin >> n >> m;
    //иницилизируем список смежности и массив посещенных вершин
    vector<vector<int>> adj_list(n, vector<int>());
    Color.resize(n + 1, 0);
    list_comp.resize(n + 1, vector<int>());
    //ввод ребер
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj_list[x - 1].push_back(y - 1);
        adj_list[y - 1].push_back(x - 1);
    }
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        if (Color[i] == 0){
            shortDFS(adj_list, i, count);
            count++;
            // cout << count << endl;

        }
    }
    // cout << "yo";
    count--;
    cout << count << endl;
    for(int i = 1; i <=count; i++)
    {
        cout << list_comp[i].size() << endl;
        for(long int j = 0; j < list_comp[i].size(); j++)
        {
            cout << list_comp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

void shortDFS(vector <vector<int> > & G, int cur, int count)
{
    Color[cur] = count;
    list_comp[count].push_back(cur + 1);
    for (auto x : G[cur])
    {
        if (Color[x] != count) shortDFS(G, x, count);
    }
    return;
}

// int N, S;
// 	cin>>N>>S;
// 	S--;
// 	int matrix [N][N];
// 	for(int i = 0; i < N; i++)
// 		for(int j = 0; j < N; j++)
// 			cin>>matrix[i][j];
// 	vector <vector<int> > G_mat(N);
// 	for (int i =0; i < N ; i ++)
// 	    for (int j =0; j < N ; j ++)
// 	    {
// 	        if (matrix[i][j])// Ребро есть
// 	        {
// 	            G_mat[i].push_back(j);
// 	        }
// 	    }
