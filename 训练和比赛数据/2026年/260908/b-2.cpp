#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define range(a) a.begin(), a.end()
#define ios ios::sync_with_stdio(false);cin.tie(0);

string solve() {
    int n; cin >> n;
    vector<pair<char, ll>> op;
    for (int i = 0; i < n; i++) {
        char c; ll x; cin >> c >> x;
        op.emplace_back(c, x);
    }
    map<ll, int> t;
    vector<int> l(n, -1);
    for (int i = n - 1; i >= 0; i--) {
        auto& [c, x] = op[i];
        if (c == 'T') {
            if (!t.count(x)) t[x] = i;
        } else if (c == 'F') {
            t.erase(x);
        } else {
            l[i] = t.count(x) ? t[x] : i;
            t.erase(x);
        }
    }
    string ans = "";
    stack<pair<ll, int>> st;
    for (int i = 0; i < n; i++) {
        auto& [c, x] = op[i];

        if (c == '+') st.push({x, l[i]});

        ans += (c == '+' ? '+' : '?');

        while (!st.empty() && st.top().second <= i) {
            ans += '-';
            st.pop();
        }
    }
    return ans;
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        cout << solve();
        if (t) cout << "\n";
    }
}