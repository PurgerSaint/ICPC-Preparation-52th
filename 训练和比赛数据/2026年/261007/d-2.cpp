#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

struct state {
    ll a, b, c;
    ll s;
    ll f;
    bool k;
    bool operator<(const state& other) const {
        return s > other.s;
    } 
};

int solve() {
    int n; cin >> n;
    ll k; cin >> k;
    const ll INF = 1LL << 60;
    priority_queue<state> pq;
    for (int i = 0; i < n; i++) {
        ll a, b, c; cin >> a >> b >> c;
        ll f = INF;
        bool can = 0;
        if (a == b && b == c && c == a) {
            pq.push({a, b, c, a + b + c, 0LL, can});
            continue;
        }
        if (a > b || b > c || a > c) {
            f = 0; can = 1;
        } else {
            if (a < b && c >= min(a, b)) {
                f = min(f, c - min(a, b) + 1);
                can = 1;
            }
            if (a < c && b >= a) {
                f = min(f, b - a + 1);
                can = 1;
            }
        }
        pq.push({a, b, c, a + b + c, f == INF ? 0LL : f, can});
    }
    if ((int)pq.size() > 1)
        while (k) {
            state x = pq.top(); pq.pop();
            auto& [a, b, c, s, f, can] = x;
            if (!can || k <= 2 * f) {
                // cout << "state 1 " << s << "\n";
                return s;
            }
            auto& [a1, b1, c1, s1, f1, can1] = pq.top();
            k -= 2 * f;
            if (s + k < s1 + 1) {
                // cout << "state 3 " << s << " " << k << " " << (s1 + 1) << "\n";
                return s + k;
            }
            k -= (s1 + 1) - s;
            s = s1 + 1;
            f = 0LL;
            pq.push(x);
        }
    // cout << "state end" << "\n";
    return pq.top().s;
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        cout << solve();
        if (t) cout << "\n";
    }
    return 0;
}