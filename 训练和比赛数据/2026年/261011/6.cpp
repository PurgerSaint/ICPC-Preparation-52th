#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

struct state {
    int t;
    vector<int> loc;
    int f;
};

int main() {
    ios;
    int n; cin >> n;
    vector<state> a(n + 1);
    int ans = 0, sum = 0;
    for (int i = 1; i <= 2 * n; i++) {
        int t; cin >> t;
        a[t].loc.push_back(i);
        if ((int)a[t].loc.size() == 2) {
            a[t].f = a[t].loc[1] - a[t].loc[0] - 1;
            sum += a[t].f;
        }
    }
    sort(range(a), [](state& x, state& y){ return x.f < y.f; });
    for (int i = 1; i <= n; i++) {
        auto& [_, p1, f1] = a[i];
        for (int j = i + 1; j <= n; j++) {
            auto& [_2, p2, f2] = a[j];
            
            
        }
    }
    cout << (sum + ans);
    return 0;
}