#include <bits/stdc++.h> // https://codeforces.com/group/QmrArgR1Jp/contest/257752/problem/D
using namespace std;

#define ll long long
#define INF 1000000000

int main() {

    deque<int> q1;
    deque<int> q2;
    int n, id;
    string command;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> command;
        if (command == "+") {
            cin >> id;
            q1.push_back(id);
            while (q1.size() > q2.size()) {
                // ...
                q2.push_back(q1.front());
                q1.pop_front();
            }
        } else if (command == "*") {
            cin >> id;
            q2.push_back(id);
            while (q1.size() + 1 < q2.size()) {
                q1.push_front(q2.back());
                q2.pop_back();
            }
        } else if (command == "-") {
            cout << q2.front() << endl;
            q2.pop_front();
            while (q1.size() > q2.size()) {
                // ...
                q2.push_back(q1.front());
                q1.pop_front();
            }
        }
    }

    return 0;
}
