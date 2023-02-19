#include <bits/stdc++.h> // https://codeforces.com/group/QmrArgR1Jp/contest/257752/problem/E
using namespace std;

#define ll long long
#define INF 1000000000

int main() {

    stack<int> s;
    int a, b;
    string str;
    while (cin >> str)
    {
        if (str == "+" || str == "-" || str == "*")
		{
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();

			if(str == "+")
			{
                a += b;
                s.push(a);
            }
			if(str == "-")
			{
                a = b - a;
                s.push(a);
			}
			if(str == "*")
			{
                a *= b;
                s.push(a);
			}
		}
		else s.push(stoi(str));
    }
    cout << s.top();
    return 0;
}
