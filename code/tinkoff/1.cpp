#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000

int main() {

    int bad = 0;
    string word, colors;
    getline(cin, word);
    getline(cin, colors);

    // cin >> colors;
    int flag = 0;
    int counter = 1;
    char last = colors[0];
    if (word.length() > 1) {
        for (size_t i = 1; i < word.length(); i++) {
            if (word[i] == ' ') {
                last = ' ';
                continue;
            }
            if (last == ' ') {
                last = colors[counter];
                counter++;
                continue;
            }
            if (last == colors[counter]) {
                bad++;
                last = '!';
                counter++;
            }
            else {
                if (last != '!') last = colors[counter];
                counter++;
            }
        }
        cout << endl << bad;
    }
    else cout << 0;
    return 0;
}
