#include <bits/stdc++.h> // https://codeforces.com/group/QmrArgR1Jp/contest/257752/problem/C
using namespace std;

#define ll long long
#define INF 1000000000

int main() {
    map<int, int> people;
    int pos = 0;
    deque<int> d;
    int command, n, number;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> command;
        if (command == 1)
        {
            cin >> number;
            people[number] = pos;
            pos++;
            d.push_back(number);
        }
        if (command == 2)
        {
            d.pop_front();
        }
        if (command == 3)
        {
            d.pop_back();
            --pos;
        }
        if (command == 4)
        {
            cin >> number;
            cout << people[number] - people[d.front()] << endl;
        }
        if (command == 5)
        {
            cout << d.front() << endl;
        }
        // for (int j = 0; j < d.size(); j++)
        // {
        //     cout << people[d[j]] << " ";
        // }
        // cout << endl;
    }
    return 0;
}
