#include <bits/stdc++.h> //2859 ПЕРЕПИСАТЬ

using namespace std;
#define ll long long
int main() {
    int n;
    cin >> n;
    vector<int> a(n), colors(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    set<pair<int, int>> st;
    for (int i = n - 1; i >= 0; --i) {
        auto res = st.lower_bound({a[i] + 1, 0});
        if (res == st.end()) {
            colors[i] = ++cnt;
            st.insert({a[i], cnt});
        }
        else {
            colors[i] = res->second;
            st.erase(res);
            st.insert({a[i], colors[i]});
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < n; i++) {
        cout << colors[i] << " ";
    }
    return 0;
}
