#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

bool solve() {
    int n; cin >> n;
    vector<int> pos(n + 1), target(n + 1);
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        pos[t] = i;
    }
    int cnt_odd = 0, cnt_even = 0;

    for (int i = n; i >= 1; i--) {
        if (pos[i] % 2) cnt_odd++;
        else cnt_even++;

        if (abs(cnt_even - cnt_odd) > 1) return 0;
    }
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