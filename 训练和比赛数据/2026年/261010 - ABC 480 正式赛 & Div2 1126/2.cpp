#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

void solve() {
    int n; ll k; cin >> n >> k;
    for (int i = 1; i < n; i++)
        cout << 0 << " ";
    cout << k;
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
/*
1 + 32 + 16 + 2
110011
4 + 8 -> 39
32 + 16 
*/
