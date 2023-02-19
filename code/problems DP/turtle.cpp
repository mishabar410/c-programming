#include <bits/stdc++.h> // https://codeforces.com/group/QmrArgR1Jp/contest/261523/problem/B
using namespace std;

#define ll long long
#define INF 1000000000

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> field(n, vector <int>(m));
    vector<vector<int>> dp(n, vector <int>(m, (-1) * INF));
    vector<vector<char>> from(n, vector <char>(m, 'O'));
    from[0][0] = 'X';
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> field[i][j];
    dp[0][0] = field[0][0];

    for (int i = 1; i < n; i++) {
        from[i][0] = 'D';
        dp[i][0] = field[i][0] + dp[i - 1][0];
    }
    for (int i = 1; i < m; i++) {
        from[0][i] = 'R';
        dp[0][i] = field[0][i] + dp[0][i - 1];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (dp[i][j] < dp[i][j - 1] + field[i][j]) {
                from[i][j] = 'R';
                dp[i][j] = dp[i][j - 1] + field[i][j];
            }
            if (dp[i][j] < dp[i - 1][j] + field[i][j]) {
                from[i][j] = 'D';
                dp[i][j] = dp[i - 1][j] + field[i][j];
            }
        }
    }
    cout << dp[n - 1][m - 1] << endl;
    stack<char> backtrack;
    int i_tmp = n - 1;
    int j_tmp = m - 1;
    char tmp = from[n - 1][m - 1];
    while (tmp != 'X') {
        backtrack.push(tmp);
        if (tmp == 'R') j_tmp--;
        else i_tmp--;
        tmp = from[i_tmp][j_tmp];
    }
    while (!backtrack.empty()) {
        cout << backtrack.top();
        backtrack.pop();
    }
    cout << endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}
