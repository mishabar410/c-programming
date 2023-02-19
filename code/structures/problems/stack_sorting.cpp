#include <bits/stdc++.h> //https://codeforces.com/group/QmrArgR1Jp/contest/257752/problem/F
using namespace std;

#define ll long long
#define INF 1000000000

int main() {
    list<string> commands;
    list<int> s1;
    stack<int> s2;
    int n, number, counter = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> number;
        while ((!s2.empty()) && s2.top() == counter) {
            commands.push_front("pop");
            s2.pop();
            counter++;
        }
        if (number == counter) {
            commands.push_front("push");
            commands.push_front("pop");
            counter++;
        } else {
            commands.push_front("push");
            s2.push(number);
        }
    }
    while((!s2.empty()) && s2.top() == counter) {
        commands.push_front("pop");
        s2.pop();
        counter++;
    }
    if (!s2.empty()) cout << "impossible" << endl;
    else {
        while(!commands.empty()) {
            cout << commands.back() << endl;
            commands.pop_back();
        }
    }

    return 0;
}
