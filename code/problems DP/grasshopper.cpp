#include <bits/stdc++.h> // https://codeforces.com/group/QmrArgR1Jp/contest/261523/problem/A
using namespace std;

#define ll long long
#define INF 1000000000

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> column(n);
    vector<int> dp(n, -1 * INF);
    vector<int> before(n);

    for (int i = 1; i < n - 1; i++)
        cin >> column[i];

    column[0] = 0;
    column[n - 1] = 0;
    dp[0] = column[0];

    for (int i = 1; i < n; i++)
        for (int j = i - 1; j >= max(0, i - k); j--) {
            // dp[i] = max(dp[i], dp[j] + column[i]);
            if (dp[i] < dp[j] + column[i]) {
                before[i] = j;
                dp[i] = dp[j] + column[i];
            }
        }
    cout << dp[n - 1] << endl;

    stack<int> backtrack;
    int tmp = n - 1;
    backtrack.push(tmp);
    while (tmp != 0) {
        backtrack.push(before[tmp]);
        tmp = before[tmp];
    }
    // for (int i = 0; i < n; i++) cout << before[i] << " ";
    //
    // cout << endl;
    // backtrack.pop();
    cout << backtrack.size() - 1 << endl;
    while (!backtrack.empty()) {
        cout << backtrack.top() + 1 << " ";
        backtrack.pop();
    }
    cout << endl;
    return 0;
}
