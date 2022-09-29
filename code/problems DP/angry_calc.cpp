#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define ld long double
#define PI 3.14159265358979323846
using namespace std;

const ld INF = 1e18;

using namespace std;
string s;
vector <ld> nums;
vector <char> operations;
vector<vector<ld>> dp(100, vector <ld>(100, (-1) * INF));
vector<vector<ld>> mn(100, vector <ld>(100, INF));
vector<char> open_brackets(100, 0);
vector<int> close_brackets(100, 0);

void find_brackets(int start, int finish, int flag);

int main() {
    getline(cin, s);
    string k = "";
    for (int i=0; i < s.size(); ++i) {
        if (s[i] == '+' || s[i] == '*' || s[i] == '-') {
            if (k != "") {
                nums.push_back(atof(k.c_str()));
                k = "";
            }

            k = "";
            operations.push_back(s[i]);
        }
        else if (s[i] == ' ') {
            if (k != "") {
                nums.push_back(atof(k.c_str()));
                k = "";
            }
        }
        else {
            k += s[i];
        }
    }
    if (k != "")  nums.push_back(atof(k.c_str()));
    if(nums.size() == 1) {
        cout << nums[0] << endl << nums[0];
        return 0;
    }
    for (int i = 0; i < nums.size(); i++) {
        dp[i][i] = nums[i];
        mn[i][i] = nums[i];
    }

    for (int l = 1; l < nums.size(); l++) {
        for (int st = 0; st < nums.size() - l; st++) {
            for (int j = st; j < st + l; j++) {
                if (operations[j] == '+') {
                    mn[st][st + l] = min(mn[st][st + l], mn[st][j] + mn[j + 1][st + l]);
                    dp[st][st + l] = max(dp[st][st + l], dp[st][j] + dp[j + 1][st + l]);
                }
                if (operations[j] == '-') {
                    mn[st][st + l] = min(mn[st][st + l], mn[st][j] - dp[j + 1][st + l]);

                    dp[st][st + l] = max(dp[st][st + l], dp[st][j] - mn[j + 1][st + l]);
                }
                if (operations[j] == '*') {
                    mn[st][st + l] = min(mn[st][st + l], dp[st][j] * dp[j + 1][st + l]);
                    mn[st][st + l] = min(mn[st][st + l], mn[st][j] * mn[j + 1][st + l]);
                    mn[st][st + l] = min(mn[st][st + l], dp[st][j] * mn[j + 1][st + l]);
                    mn[st][st + l] = min(mn[st][st + l], mn[st][j] * dp[j + 1][st + l]);

                    dp[st][st + l] = max(dp[st][st + l], dp[st][j] * dp[j + 1][st + l]);
                    dp[st][st + l] = max(dp[st][st + l], mn[st][j] * mn[j + 1][st + l]);
                    dp[st][st + l] = max(dp[st][st + l], mn[st][j] * dp[j + 1][st + l]);
                    dp[st][st + l] = max(dp[st][st + l], dp[st][j] * mn[j + 1][st + l]);
                }
            }
        }
    }
    cout << dp[0][nums.size() - 1] << endl;
    find_brackets(0, nums.size() - 1, 1);
    for (int i = 0; i < nums.size(); i++) { // ВЫВОД ИТОГОВОГО ВЫРАЖЕНИЯ
        while(open_brackets[i]) {           //сначала выводим все открывающиеся скобки
            cout << '(';
            open_brackets[i]--;
        }
        cout << nums[i];                    //сам элемент
        while(close_brackets[i]) {          //все закрывающиеся скобки
            cout << ')';
            close_brackets[i]--;
        }
        if (i != nums.size() - 1) cout << operations[i];
    }
    return 0;
}

void find_brackets(int start, int finish, int flag) {
    if (start == finish) return;
    open_brackets[start]++;
    close_brackets[finish]++;
    for (int i = start; i <= finish; i++) {
        if (flag) {
            if (operations[i] == '+' && (dp[start][finish] == dp[start][i] + dp[i + 1][finish])) {
                find_brackets(start, i, 1);
                find_brackets(i + 1, finish, 1);
                return;
            }
            if (operations[i] == '-' && (dp[start][finish] == dp[start][i] - mn[i + 1][finish])) {
                find_brackets(start, i, 1);
                find_brackets(i + 1, finish, 0);
                return;
            }
            if (operations[i] == '*') {
                if (dp[start][finish] == dp[start][i] * dp[i + 1][finish]) {
                    find_brackets(start, i, 1);
                    find_brackets(i + 1, finish, 1);
                    return;
                }
                if (dp[start][finish] == dp[start][i] * mn[i + 1][finish]) {
                    find_brackets(start, i, 1);
                    find_brackets(i + 1, finish, 0);
                    return;
                }
                if (dp[start][finish] == mn[start][i] * dp[i + 1][finish]) {
                    find_brackets(start, i, 0);
                    find_brackets(i + 1, finish, 1);
                    return;
                }
                if (dp[start][finish] == mn[start][i] * mn[i + 1][finish]) {
                    find_brackets(start, i, 0);
                    find_brackets(i + 1, finish, 0);
                    return;
                }
            }
        }
        else {
            if (operations[i] == '+' && (mn[start][finish] == mn[start][i] + mn[i + 1][finish])) {
                find_brackets(start, i, 0);
                find_brackets(i + 1, finish, 0);
                return;
            }
            if (operations[i] == '-' && (mn[start][finish] == mn[start][i] - dp[i + 1][finish])) {
                find_brackets(start, i, 0);
                find_brackets(i + 1, finish, 1);
                return;
            }
            if (operations[i] == '*') {
                if (mn[start][finish] == dp[start][i] * dp[i + 1][finish]) {
                    find_brackets(start, i, 1);
                    find_brackets(i + 1, finish, 1);
                    return;
                }
                if (mn[start][finish] == dp[start][i] * mn[i + 1][finish]) {
                    find_brackets(start, i, 1);
                    find_brackets(i + 1, finish, 0);
                    return;
                }
                if (mn[start][finish] == mn[start][i] * dp[i + 1][finish]) {
                    find_brackets(start, i, 0);
                    find_brackets(i + 1, finish, 1);
                    return;
                }
                if (mn[start][finish] == mn[start][i] * mn[i + 1][finish]) {
                    find_brackets(start, i, 0);
                    find_brackets(i + 1, finish, 0);
                    return;
                }
            }
        }
    }
}
