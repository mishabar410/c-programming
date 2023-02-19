#include <cstdio> // https://codeforces.com/group/QmrArgR1Jp/contest/257752/problem/B
#include <iostream>
#include <stack>
using namespace std;

#define ll long long
#define INF 1000000000

int main() {
    stack<pair<int, int>> st;
    int n, ball, count = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ball);
        if (st.empty()) st.push(make_pair(ball, 1));
        else if (st.top().first != ball)
        {
            if (st.top().second >= 3)
            {
                count += st.top().second;
                st.pop();
            }
            if (st.top().first != ball) st.push(make_pair(ball, 1));
            else st.top().second++;
        }
        else st.top().second++;
    }
    if (st.top().second >= 3)
    {
        count += st.top().second;
        st.pop();
    }
    cout << count;
    return 0;
}
