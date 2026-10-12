#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> cnt(n + 1, 0), parent(n + 1, 0), t(n + 1, 0), fu(n + 1, 0);
    vector<bool> f(n + 1, 0);

    for (int i = 1; i <= n; i++) parent[i] = i;

    for (int i = 1; i <= n; i++) {
        if (f[i]) continue;
        f[i] = 1;
        t[i] = 0;
        int u = i, pa = i;
        vector<int> cycle;
        cycle.push_back(i);
        while (true) {
            int v = a[u];
            if (f[v]) {
                // cout << "end:" << v << " cnt:" << cnt[u] << "\n";
                fu[v] = cnt[v];
                cnt[v] = cnt[u] + 1 - cnt[v];
                pa = v;
                break;
            }
            f[v] = 1;
            t[v] = t[u] + 1;
            cnt[v] = cnt[u] + 1;
            parent[v] = u;
            // cout << v << " from " << u << " get " << cnt[v] << " time " << t[v] << " parent " << parent[v] << "\n";
            cycle.push_back(v);
            u = v;
        }
        while (!cycle.empty()) {
            int& u = cycle.back();
            if (t[u] <= t[pa]) break;
            parent[u] = pa;
            cnt[u] = 1;
            cycle.pop_back();
        }
    }

    /*
    cout << "cnt: ";
    for (int i = 1; i <= n; i++)
        cout << cnt[i] << (i < n ? " " : "\n");
    cout << "parent: ";
    for (int i = 1; i <= n; i++)
        cout << parent[i] << (i < n ? " " : "\n");*/
    
    int cnt_l = 0, cnt_s = 0, ot = n;
    for (int i = 1; i <= n; i++)
        if (parent[i] == i) {
            if (cnt[i] > 2) cnt_l++;
            else cnt_s++;
            ot -= fu[i] + cnt[i];
        }
    // cout << cnt_l << " " << cnt_s << " " << ot << "\n";
    
    int mx_ans = cnt_l + (ot > 0 || cnt_s > 0);
    int mn_ans = cnt_l + cnt_s + (ot > 0 && cnt_s == 0);
    cout << mx_ans << " " << mn_ans;
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