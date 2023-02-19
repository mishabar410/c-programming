#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000

int main() {
    int n;
    cin >> n;
    ll min_div = 1;
    for (ll i = 2; i < sqrt(n) + 1; i++) {
        if (n % i == 0) {
            min_div = i;
            break;
        }
    }
    if (min_div == 1) cout << 1 << " " << n - 1;
    else cout << n / min_div << " " << n - n / min_div;
    return 0;
}
