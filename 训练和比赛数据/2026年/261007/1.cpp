#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

bool solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    return s.find('1') <= t.find('1');
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        cout << (solve() ? "Yes" : "No");
        if (t) cout << "\n";
    }
    return 0;
}