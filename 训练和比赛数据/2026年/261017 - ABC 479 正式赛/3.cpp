#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

bool solve() {
    int n; cin >> n;
    int cnt_a = 0, cnt_b = 0;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        cnt_a += (t % 2 == 0);
        cnt_b += (t % 2 == 1);
    }
    if (cnt_b % 2 == 0 || n == 1 || cnt_a > 1) return 1;
    if (cnt_b > 1 && (cnt_a > 0 || cnt_b > 3)) return 1;
    return 0; 
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        cout << (solve() ? "Moggity" : "Larpity");
        if (t) cout << "\n";
    }
    return 0;
}