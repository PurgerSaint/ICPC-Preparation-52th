#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

void solve() {
    int n; cin >> n;
    vector<set<int>> mp(n + 1);
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        mp[i].insert(t);
        mp[t].insert(i);
    }

    vector<bool> f(n + 1, 0);
    int cycle = 0, chain = 0;

    for (int i = 1; i <= n; i++) {
        if (f[i]) continue;

        queue<int> q;
        vector<int> path;
        q.push(i);
        f[i] = 1;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            path.push_back(u);

            for (const int& v: mp[u]) {
                if (f[v]) continue;
                f[v] = 1;
                q.push(v);
            }
        }

        bool is_chain = 0;
        for (int& u: path) {
            if (mp[u].size() == 1) {
                is_chain = 1;
                break;
            }
        }
        if (is_chain) chain++;
        else cycle++;
    }
    int max_ans = cycle + chain;
    int min_ans = cycle + (chain > 0);
    cout << min_ans << " " << max_ans;
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