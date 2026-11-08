#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

bool solve() {
    int n, k; cin >> n >> k;
    int cnt_a1 = 0, cnt_b1 = 0;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        if (t % 2 == 1) cnt_a1++;
    }
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        if (t % 2 == 1) cnt_b1++;
    }
    int cnt_a2 = n - cnt_a1, cnt_b2 = n - cnt_b1;
    if (k % 2 == 1 && cnt_a1 > cnt_b1) return 0;
    if (k % 2 == 0 && cnt_a2 > cnt_b2) return 0;
    return 1;
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