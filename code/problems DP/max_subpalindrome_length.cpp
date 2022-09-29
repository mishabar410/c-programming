#include <bits/stdc++.h>

using namespace std;
//3130
int main() {
    string s;
    getline(cin, s);
    vector<vector<int>> dp(s.size(), vector<int>(s.size()));
    // cout << s.size() << endl;
    if (s.size() == 0) cout << 1 << endl;
    for(int i = 0; i < s.size(); i++) dp[i][i] = 1;

    for(int l = 1; l < s.size(); l++){
        for(int st = 0; st < s.size() - l; st++){
            if (l == 1)
            {
                if (s[st] == s[st + l]) dp[st][st + l] = 2;
                else dp[st][st + l] = 1;
            }
            else
            {
                if (s[st] == s[st + l]){
                    dp[st][st + l] = max(max(dp[st][st + l - 1], dp[st + 1][st + l]), dp[st + 1][st + l - 1] + 2);
                }
                else dp[st][st + l] = max(max(dp[st][st + l - 1], dp[st + 1][st + l]), dp[st + 1][st + l - 1]);
            }
        }
    }
    // for(int l = 1; l < s.size(); l++)
    // {
    //     for(int st = 0; st < s.size() - l; st++)
    //     {
    //         if ((st == 0) || (st + l + 1 == s.size()))
    //                 dp[st][st + l] = max(dp[st + 1][st + l], dp[st][st + l - 1]);
    //         if (s[st + 1] == s[st + l - 1])
    //                 dp[st][st + l] = dp[st + 1][st + l - 1] + 1;
    //         else dp[st][st + l] = dp[st + 1][st + l - 1];
    //     }
    // }
    cout << dp[0][s.size() - 1];
    return 0;
}
