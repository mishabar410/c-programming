#include <bits/stdc++.h> // https://codeforces.com/group/QmrArgR1Jp/contest/257752/problem/H
using namespace std;

#define ll long long
#define INF 1000000000

vector<int> parent;
vector<int> struct_rank;
// vector<int> minimal;
// vector<int> maximal;
// vector<int> count_elements;
vector<int> was_parent;
vector<int> self_xp;
vector<int> xp;




void make_set (int v) {
	parent[v] = v;
	struct_rank[v] = 0;
    // minimal[v] = v;
    // maximal[v] = v;
    // count_elements[v] = 1;
}

int find_set (int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set (parent[v]);
}

int find_first_parent (int v) {
	if (was_parent[v])
		return v;
	return parent[v] = find_first_parent (parent[v]);
}


void union_sets (int a, int b) {
	a = find_set (a);
	b = find_set (b);
	if (a != b) {
		if (struct_rank[a] < struct_rank[b])
			swap (a, b);
		parent[b] = a;
		if (struct_rank[a] == struct_rank[b])
			++struct_rank[a];
	}
}

int get_xp(int a) {
	int count = self_xp[a];
	int p = a;
	while(find_set(p) != find_first_parent(p)) {
		if (was_parent[p] == 1) {
			was_parent[p] = 0;
			new_p = find_first_parent[p]
			was_parent[p] = 1;
			count += xp[find_first_parent[p]];
		} else {
			new_p = find_first_parent[p]
			count += xp[find_first_parent[p]];
		}
		p = new_p;
	}
	return count;
}

int main() {
    int n, number1, number2;
    cin >> n;
    parent.resize(n + 1);
    struct_rank.resize(n + 1);
    was_parent.resize(n + 1);
	self_xp.resize(n + 1);
	xp.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        make_set(i);
    }

    string command;
    while(cin >> command) {
        if (command == "join") {
            cin >> number1 >> number2;
            union_sets(number1, number2);
        } else if (command == "get") {
            cin >> number1;
            cout << get_xp(number1) << endl;
        } else if (command == "add") {
			cin >> number1 >> number2;
			if (number1 == find_set(number1)) self_xp[number1] += number2;
			else {
				number1 = find_set[number1];
				xp[number1] += number2;
			}
		}

    }
    return 0;
}
