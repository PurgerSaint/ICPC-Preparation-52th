#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n, q; cin >> n >> q;
    vector<pair<int, bool>> a;
    for (int i = 1; i <= n; i++)
        a.push_back({i, 1});
    while (q--) {
        int k; cin >> k;
        for (int i = 0; i < k; i++)
            a[i].second = !a[i].second;
        reverse(a.begin(), a.begin() + k);
        // for (int i = 0; i < k / 2; i++) swap(a[i], a[k - i - 1]);
    }
    for (auto it = a.begin(); it != a.end(); it++) {
        auto& [x, f] = *it;
        cout << (f ? "" : "-") << x << (it + 1 != a.end() ? "\n" : "");
    }
    return 0;
}