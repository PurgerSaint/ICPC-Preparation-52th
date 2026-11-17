#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

bool solve() {
    int n; cin >> n;
    string s, r; cin >> s >> r;
    int a = 0;
    for (char c: s) a += (c == '1');
    int b = n - a;
    vector<pair<char, int>> buk;
    for (int i = n - 2; i >= 0; i--) {
        if (buk.empty() || buk.back().first != r[i])
            buk.push_back({r[i], 1});
        else buk.back().second++;
    }
    int cnt = 0;
    while (!buk.empty()) {
        auto [c, t] = buk.back(); buk.pop_back();
        if (a == 0 || b == 0 || cnt >= n - 1) break;
        while (a + b > 1) {
            if (cnt >= n - 1 || t <= 0) break;
            if (a == 0 || b == 0) break;
            int g = min(t, min(a, b));
            a -= g, b -= g, t -= g;
            cnt += g;
            (c == '1' ? a : b) += g;
        }
        if (t > 0) break;
    }
    // cout << a << " " << b << " " << cnt << "\n";
    return cnt >= n - 1;
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        cout << (solve() ? "YES" : "NO");
        if (t) cout << "\n";
    }
    return 0;
}