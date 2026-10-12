#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int loc(string s) {
    if (s == "BG") return 0;
    else if (s == "BR") return 1;
    else if (s == "BY") return 2;
    else if (s == "GR") return 3;
    else if (s == "GY") return 4;
    return 5;
}

void solve() {
    int n, q; cin >> n >> q;
    vector<vector<int>> a(6);
    vector<string> s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        a[loc(s[i])].push_back(i);
    }
    while (q--) {
        int x, y; cin >> x >> y;
        if (x > y) swap(x, y);

        int f = 2 * n + 1;
        for (char c1: s[x]) {
            for (char c2: s[y]) {
                if (c1 == c2) {
                    f = 0; break;
                }
                string t = "";
                t += min(c1, c2);
                t += max(c1, c2);

                vector<int>& p = a[loc(t)];
                if (p.empty()) continue;

                auto it1 = upper_bound(range(p), x);
                auto it2 = lower_bound(range(p), y);
                if (it1 != p.end() && it2 > it1) {
                    f = 0; break;
                }

                auto it3 = lower_bound(range(p), x);
                if (it3 != p.begin()) f = min(f, 2 * (x - *prev(it3)));

                auto it4 = upper_bound(range(p), y);
                if (it4 != p.end()) f = min(f, 2 * (*it4 - y));
            }
            if (f == 0) break;
        }
        if (f == 2 * n + 1) {
            cout << -1 << (q ? "\n" : "");
            continue;
        }
        cout << (abs(x - y) + f) << (q ? "\n" : "");
    }
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        solve();
        if (t) cout << "\n";
    }
    return 0;
}