#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

bool solve() {
    vector<int> a(3);
    for (int i = 0; i < 3; i++) cin >> a[i];
    sort(range(a));
    return a[0] + 1 == a[1] && a[2] - 1 == a[1];
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