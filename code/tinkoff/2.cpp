#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000

int main() {
    int a, b, c, x, y, z;
    cin >> a >> b >> c >> x >> y >> z;
    int sum = x / a + y / b + z / c;
    uint64_t fin = (sum + 1) * (sum + 2) / 2;
    cout << fin;
    // sum = x / a + y / b + z / c
    // (n + 2)! / 2 * (n + 2 - 2)! = (n + 2) * (n + 1) / 2
    return 0;
}
