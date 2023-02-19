#include <bits/stdc++.h> // https://codeforces.com/group/QmrArgR1Jp/contest/261523/problem/C
using namespace std;

#define ll long long
#define INF 1000000000

int main() {
    int n;
    int maximum = 1;
    int max_ind = 0;
    cin >> n;
    vector<int> seq(n);
    vector<int> before(n, -1);
    vector<int> dp(n, 1);
    before[0] = -1;
    for (int i = 0; i < n; i++) cin >> seq[i];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (seq[j] < seq[i] && dp[j] >= dp[i]) {
                dp[i] = dp[j] + 1;
                before[i] = j;
                if (dp[i] > maximum) {
                    maximum = dp[i];
                    max_ind = i;
                }
            }
        }
    }

    cout << maximum << endl;
    stack<int> backtrack;
    int tmp = max_ind;
    while(tmp != -1) {
        backtrack.push(seq[tmp]);
        tmp = before[tmp];
    }
    while (!backtrack.empty()) {
        cout << backtrack.top() << " ";
        backtrack.pop();
    }
    cout << endl;
    return 0;
}
