#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

int main() {
    ios;
    string s; cin >> s;
    char a, b; cin >> a >> b;
    for (char& t: s)
        if (t != a && t != b) {
            cout << t;
            break;
        }
    return 0;
}