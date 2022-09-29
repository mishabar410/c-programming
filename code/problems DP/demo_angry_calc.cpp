#include <bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
#define ull unsigned long long
#define ll long long
#define ld long double
#define PI 3.14159265358979323846
using namespace std;

const ld INF = 1e18;

ll n;
string s;
vector<ld> v;
vector<string> v1;
vector<char> z;
vector<vector<ld>> dp, mn;
vector<vector<ll>> used;
vector<vector<vector<ll>>> p, p1;

void f(ll l, ll r) {
    if (used[l][r]) return;
    if (l == r) {
        dp[l][l] = v[l];
        mn[l][l] = v[l];
        return;
    }
    used[l][r] = 1;
    for (int i=l; i < r; ++i) {
        f(l, i);
        f(i + 1, r);
        if (z[i] == '+') {
            if (dp[l][r] < dp[l][i] + dp[i + 1][r]) {
                dp[l][r] = dp[l][i] + dp[i + 1][r];
                p[l][r] = {i, 1, 1};
            }
            if (mn[l][r] > mn[l][i] + mn[i + 1][r]) {
                mn[l][r] = mn[l][i] + mn[i + 1][r];
                p1[l][r] = {i, 0, 0};
            }
        } else if (z[i] == '*') {
            if (dp[l][r] < dp[l][i] * dp[i + 1][r]) {
                dp[l][r] = dp[l][i] * dp[i + 1][r];
                p[l][r] = {i, 1, 1};
            }
            if (dp[l][r] < mn[l][i] * mn[i + 1][r]) {
                dp[l][r] = mn[l][i] * mn[i + 1][r];
                p[l][r] = {i, 0, 0};
            }
            if (dp[l][r] < mn[l][i] * dp[i + 1][r]) {
                dp[l][r] = mn[l][i] * dp[i + 1][r];
                p[l][r] = {i, 0, 1};
            }
            if (dp[l][r] < dp[l][i] * mn[i + 1][r]) {
                dp[l][r] = dp[l][i] * mn[i + 1][r];
                p[l][r] = {i, 1, 0};
            }

            if (mn[l][r] > dp[l][i] * dp[i + 1][r]) {
                mn[l][r] = dp[l][i] * dp[i + 1][r];
                p1[l][r] = {i, 1, 1};
            }
            if (mn[l][r] > mn[l][i] * mn[i + 1][r]) {
                mn[l][r] = mn[l][i] * mn[i + 1][r];
                p1[l][r] = {i, 0, 0};
            }
            if (mn[l][r] > mn[l][i] * dp[i + 1][r]) {
                mn[l][r] = mn[l][i] * dp[i + 1][r];
                p1[l][r] = {i, 0, 1};
            }
            if (mn[l][r] > dp[l][i] * mn[i + 1][r]) {
                mn[l][r] = dp[l][i] * mn[i + 1][r];
                p1[l][r] = {i, 1, 0};
            }
        } else {
            if (dp[l][r] < dp[l][i] - mn[i + 1][r]) {
                dp[l][r] = dp[l][i] - mn[i + 1][r];
                p[l][r] = {i, 1, 0};
            }
            if (mn[l][r] > mn[l][i] - dp[i + 1][r]) {
                mn[l][r] = mn[l][i] - dp[i + 1][r];
                p1[l][r] = {i, 0, 1};
            }
        }
    }
}

string rec(ll l, ll r, ll x) {
    if (l == r) {
        return v1[l];
    }
    ll k, x1, x2;
    if (x == 1) {
        k = p[l][r][0], x1 = p[l][r][1], x2 = p[l][r][2];
    } else {
        k = p1[l][r][0], x1 = p1[l][r][1], x2 = p1[l][r][2];
    }
    if (z[k] == '+') {
        return '(' + rec(l, k, x1) + ")+(" + rec(k + 1, r, x2) + ')';
    } else if (z[k] == '*') {
        return '(' + rec(l, k, x1) + ")*(" + rec(k + 1, r, x2) + ')';
    } else {
        return '(' + rec(l, k, x1) + ")-(" + rec(k + 1, r, x2) + ')';
    }
}

int main() {
    getline(cin, s);
    n = s.size();
    string k = "";
    for (int i=0; i < n; ++i)
    {
        if (s[i] == '+' || s[i] == '*' || s[i] == '-') //встретили знак, нужно проверить вдруг он оборвал число
        {
            if (k != "")                                //оборвал
            {
                v.push_back(atof(k.c_str())); //v массив чисел, v1 массив чисел в string
                v1.push_back(k);
                k = "";
            }

            k = "";
            z.push_back(s[i]);                          //z - массив +-*
        }
        else if (s[i] == ' ')                           //встретили пробел, нужно проверить вдруг он оборвал число
        {
            if (k != "")                                //оборвал
            {
                v.push_back(atof(k.c_str()));
                v1.push_back(k);
                k = "";
            }
        }
        else                                            //продолжаем число
        {
            k += s[i];
        }
    }

    if (k != "")                                        //строка закончилась вставляем последнее число
    {
        v.push_back(atof(k.c_str()));
        v1.push_back(k);
    }

    n = v.size();
    dp.resize(n, vector<ld> (n, -INF));
    mn.resize(n, vector<ld> (n, INF));
    used.resize(n, vector<ll> (n));
    p.resize(n, vector<vector<ll>> (n));
    p1.resize(n, vector<vector<ll>> (n));
    f(0, n - 1);
    ld ans = dp[0][n - 1];
    cout << ans << '\n';
    cout << rec(0, n - 1, 1);
}
